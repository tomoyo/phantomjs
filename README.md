# [PhantomJS](http://phantomjs.org) - Scriptable Headless WebKit
## phantomjs 2.1 support download files

```js
    page.onResourceReceived = function(response) {
    	if(response.contentType =="application/zip"){
    	 	var filename = response.headers[5].value.match(/"(.+?)"/)[1];
    	 	var responseNumber = filename.match(/\d+-\d+/)[0];
    	  	page.onFilePicker = function(){
    		 	console.log("save file:"+filename);
    		    return filename;
    		}
        }
    }

    page.onDownloadFinished = function(status){
    	console.log('onDownloadFinished(' + status + ')');
    }
    page.onLoadFinished = function(status){
        console.log('onLoadFinished(' + status + ')');
    }
```

