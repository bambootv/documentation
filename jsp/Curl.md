1. **Curl**
```
    GET
	URL url = new URL("https://www.google.com.vn");
	HttpURLConnection connection = (HttpURLConnection) url.openConnection();
	connection.setRequestMethod("GET");
	connection.connect();
	BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
	String line = reader.readLine();
	while (line != null) {
		out.println(line);
		line = reader.readLine();
	}
```

```
    POST
        String code = request.getParameter("code");
    
    	String httpsURL = "https://graph.facebook.com/v2.8/oauth/access_token";
    
    	StringBuilder q = new StringBuilder();
    	q.append("client_id=" + URLEncoder.encode(facebook_client_id, "UTF-8"));
    	q.append("&redirect_uri=" + URLEncoder.encode(facebook_redirect_uri, "UTF-8"));
    	q.append("&client_secret=" + URLEncoder.encode(facebook_client_secret, "UTF-8"));
    	q.append("&code=" + URLEncoder.encode(code, "UTF-8"));
    
    	String query = q.toString();
    	URL myurl = new URL(httpsURL);
    	HttpsURLConnection con = (HttpsURLConnection) myurl.openConnection();
    	con.setRequestMethod("POST");
    	con.setRequestProperty("Content-length", String.valueOf(query.length()));
    	con.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");
    	con.setRequestProperty("User-Agent", "Mozilla/4.0 (compatible; MSIE 5.0;Windows98;DigExt)");
    	con.setDoOutput(true);
    	con.setDoInput(true);
    
    	DataOutputStream output = new DataOutputStream(con.getOutputStream());
    
    	output.writeBytes(query);
    
    	output.close();
    
    	DataInputStream input = new DataInputStream(con.getInputStream());
    	String s = "";
    	for (int c = input.read(); c != -1; c = input.read())
    		s += String.valueOf((char) c);
    	input.close();
    
    	JSONObject json = new JSONObject(s);
```