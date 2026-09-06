# IOT_thermo

## How to Deployment

Dans le back, il faut rajouter, ceci:

Dans server.js:

```js
const path = require("path");

app.use(express.static(path.resolve(__dirname, "./client/build")));
```

Remplacer tout les `, required: true` par rien.

Dans le terminal:

```console
  rm node_modules -fr ; 
  rm wifi/ README.md .gitignore ;
  mv web/ client/ ; 
  mv backend/* . ;
```

Deployment:

```console
heroku login -i
changeSSH mo
cd my-project/
git init
heroku git:remote -a careplant
git add .
git commit -am "make it better"
git push heroku master

heroku logs --tail 
```

