```
const Multer = require('multer');
const upload = Multer({
    storage: Multer.memoryStorage()
});

const { Storage } = require('@google-cloud/storage');
const storage = new Storage();
```

```
router.post('/new',
    upload.fields([{ name: 'content_file', maxCount: 1 }, { name: 'avatar', maxCount: 1 }]),
    async function (req, res, next) {
        let obj = {};

        let params = req.body;
        let is_new_tag = false;
        if (params.tag === '') {
            is_new_tag = true;
            params.tag = params.new_tag;
        }

        let files = req.files;
        let content_file = files['content_file'][0];

        let validator = await Track.validate({
            files: files,
            params: params
        });

        if (!validator.success) {
            return res.render('tracks/detail', {
                params: params,
                message: validator.message,
                data: {
                    status: 'error',
                    track: validator.data,
                    tags: await Track.list_tags()
                }
            });
        }

        let bucket_content_file = storage.bucket(config.bucket_name);
        const blob_content_file = bucket_content_file.file(Track.content_folder_name() + shortid.generate() + "--" + content_file.originalname);
        const blob_stream_content_file = blob_content_file.createWriteStream();
        blob_stream_content_file.on('error', async err => {
            console.log(err);
            res.render('tracks/detail',
                {
                    params: params,
                    message: err.message,
                    data: {
                        status: 'error',
                        track: validator.data,
                        tags: await Track.list_tags()
                    }
                }
            );
        });
        blob_stream_content_file.on('finish', async () => {
            console.log('Upload content file done');
            obj.google_id = blob_content_file.metadata.id;
            obj.title = content_file.originalname;

            const options = {
                version: 'v2', // defaults to 'v2' if missing.
                action: 'read',
                expires: Date.now() + 1000 * 60 * 60 * 24 * 32 // 32 days
            };

            let urls = await bucket_content_file.file(blob_content_file.metadata.name).getSignedUrl(options);
            obj.url = urls[0].replace('storage.googleapis.com/', '');
            obj.tag = params.tag;
            obj.duration = params.duration;
            obj.size = blob_content_file.metadata.size;
            obj.infor = params.infor;

            try {
                let record = await Track.create(obj, res.locals.admin.id, blob_content_file.metadata.name);
                if (record) {
                    return res.redirect(`/admin/musics/edit/${record.id}`);
                }
            } catch (err) {
                res.render('tracks/detail',
                    {
                        params: {},
                        message: err.message,
                        data: {
                            status: 'error',
                            track: validator.data,
                            tags: await Track.list_tags()
                        }
                    }
                );
            }
        });
        blob_stream_content_file.end(content_file.buffer);

        let avatar = files['avatar'][0];
        let bucket_avatar = storage.bucket(config.public_bucket_name);
        const blob_avatar = bucket_avatar.file(Track.avatar_folder_name() + shortid.generate() + "--" + avatar.originalname);
        const blob_stream_avatar = blob_avatar.createWriteStream();
        blob_stream_avatar.on('error', async err => {
            console.log(err);
            res.render('tracks/detail',
                {
                    params: params,
                    message: err.message,
                    data: {
                        status: 'error',
                        track: validator.data,
                        tags: await Track.list_tags()
                    }
                }
            );
        });
        blob_stream_avatar.on('finish', async () => {
            console.log('Upload avatar done');
            obj.avatar = `${config.public_bucket_name}/${blob_avatar.metadata.name}`;

            try {
                let record = await Track.create(obj, res.locals.admin.id, blob_content_file.metadata.name, is_new_tag);
                if (record) {
                    return res.redirect(`/admin/musics/edit/${record.id}`);
                }
            } catch (err) {
                res.render('tracks/detail',
                    {
                        params: {},
                        message: err.message,
                        data: {
                            status: 'error',
                            track: validator.data,
                            tags: await Track.list_tags()
                        }
                    }
                );
            }
        });
        blob_stream_avatar.end(avatar.buffer);
    });
```
