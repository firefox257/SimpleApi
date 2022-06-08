var $path = require("path");
var fs = require('fs');

function includeDir(path)
{
	const dirPath = $path.join(__dirname, path);
	//console.log("dirPath: " + dirPath);
	
	fs.readdir(dirPath, function(err, files)
	{
		if(err)
		{
			return consol.log(`Unable to scan directory: ${err} `);
		}
		files.map((file)=>
		{
			if(fs.lstatSync(dirPath + file).isDirectory())
			{
				//console.log("--isdir");
				includeDir(path + file);
			}
			else
			{
				//console.log(dirPath +file);
				if(file.endsWith(".js"))
				{
					include(path + file);
				}
			}
		});
	});
}




globalThis.includeDir = includeDir;

//requireDir("./");

