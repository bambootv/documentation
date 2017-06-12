**1. Database**

`group :production do`
  `gem 'pg', '0.20.0'`
`end`

`group :development, :test do`
  `gem 'sqlite3', '1.3.13'`
  `gem 'byebug',  '9.0.0', platform: :mri`
`end`

**2.Bundle install**
`bundle install --without production`

**3.Deploy to heroku**
`heroku version`

`heroku login`

`heroku keys:add` Use SSH Key

`heroku create`

`git push heroku master`

`heroku apps`

` heroku apps:destroy <app-name>`
