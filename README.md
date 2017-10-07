# [PhantomJS 2.1](http://phantomjs.org) - Scriptable Headless WebKit
## Support download files

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

## page.onInitialized on every frame

```js
    page.onInitialized = function() {

        console.log("INIT ON A FRAME");

    };
```    