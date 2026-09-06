# Zia

**(Link to Repo: https://github.com/AntoinePoisson/Zia)**

3rd year student project at Epitech which consists in creating a working HTTP/HTTPS server from scratch.

## Installation

To compile Zia, just run the bash script called "run.sh" by using the command "./run.sh" otherwise if it is not working properly you can use this one instead "bash run.sh".

Now that you have compiled the program, there should be a server running. You can either manually start a server by running the program called "zia" located at "build" and then "bin", or you can simply hit the following command: "./build/bin/zia".

## How to use ?

You have to keep in mind that there is an argument to type in, which is the path to the configuration file.
If you really need further information, just put "-h" or "--help" and then a whole bunch of information will show up.

e.g.: "./build/bin/zia --help"

Here is another exemple on how to specify a configuration file path.

e.g.: "./build/bin/zia ./config.json"

## Configuration

Please remind that the configuration file shall always be in JSON format (a.k.a.: JavaScript Object Notation).

By default, if you don't specify a configuration path, the program selects "./config.json".
If you provide a wrong configuration file, the server will never start.
Also make sure your JSON syntax is perfect, any configuration mistyped will result in a swift exit and will return 84.

Keep in mind that any configuration provided will result in a reboot on each update you do on the configuration file, or on any module described in it. The detection threshold is .33s.

Now let's dive right in the configuration section.

e.g.: Look at the following configuration file example :

```
{
  "servers": [
    {
      "ip": "127.0.0.1",
      "port": 80,
      "log": "./resources/log/Core.log",
      "secure": false
    },
    {
      "ip": "127.0.0.1",
      "port": 443,
      "log": "./resources/log/Core.log",
      "secure": true
    }
  ],
  "logger": {
    "path": "./build/modules/lib/libModuleLogger",
    "conf": "./modules/logger/conf/config.json"
  },
  "connection_wrapper": {
    "path": "./build/modules/lib/libModuleConnectionWrapper",
    "conf": "./modules/connection_wrapper/conf/config.json"
  },
  "parser": {
    "path": "./build/modules/lib/libModuleParser",
    "conf": "./modules/parser/conf/config.json"
  },
  "handlers": [
    {
      "path": "./build/modules/lib/libModuleHtmlHandler",
      "conf": "./modules/html_handler/conf/config.json"
    },
    {
      "path": "./build/modules/lib/libModulePhpCgi",
      "conf": "./modules/php_cgi/conf/config.json"
    },
    {
      "path": "./build/modules/lib/libModulePngHandler",
      "conf": "./modules/png_handler/conf/config.json"
    },
    {
      "path": "./build/modules/lib/libModuleFileExplorer",
      "conf": "./modules/file_explorer/conf/config.json"
    },
    {
      "path": "./build/modules/lib/libModuleHeadRequestHandler",
      "conf": "./modules/head_request_handler/conf/config.json"
    }
  ]
}
```

As a reminder, you shall always have the following modules valid: "connection_wrapper" and "parser" otherwise, the server won't start.
You also have to get a valid server as described under "servers" section, if you do not, the program will start and won't accept any connection until you update the proper configuration file.

## Pages and resources

You must put your pages and resources (.css, .png, .jpg, .html ...) in the following path relative from the root directory of the server: "./resources/pages", otherwise, the contents will not be taken in account.