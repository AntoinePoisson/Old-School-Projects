const { /*Client,*/ WebhookClient, MessageEmbed } = require('discord.js');
var http = require('http');

// const client = new Client();
const hook = {
    web: new WebhookClient('XXXXXXXXXXXXXXXXXX', 'XXXXXXXX_DISCORD_WEBHOOK_TOKEN_REDACTED_XXXXXXXX'),
    mobile: new WebhookClient('XXXXXXXXXXXXXXXXXX', 'XXXXXXXX_DISCORD_WEBHOOK_TOKEN_REDACTED_XXXXXXXX'),
    back: new WebhookClient('XXXXXXXXXXXXXXXXXX', 'XXXXXXXX_DISCORD_WEBHOOK_TOKEN_REDACTED_XXXXXXXX'),
}

var receive = []

const sendEmbed = (embed, branch) => {
    switch (branch) {
        case "web": return (hook.web.send(embed));
        case "mobile": return (hook.mobile.send(embed));
        case "back": return (hook.back.send(embed));
    };
}

const messageCommit = (obj) => {
    if (!(obj.sender && obj.head_commit && obj.ref))
        return;

    const branch = obj.ref.split('/')[2]
    const embed = new MessageEmbed()
        .setTitle("New Push on " + branch)
        .setColor("#5be6ff")
        .setDescription("[" + "`" + obj.head_commit.id.slice(0, 7) + "`" + "](" + obj.head_commit.url + ") " + obj.head_commit.message + " - " + obj.head_commit.author.name)
        .setURL(obj.head_commit.url)
        .setAuthor(obj.head_commit.author.name, obj.sender.avatar_url);

    sendEmbed(embed, branch)
}

const githubMessage = () => {
    while (receive.length) {
        const obj = receive.shift();

        messageCommit(obj);
    }
}

http.createServer((req, res) => {

    let data = '';

    req.on('data', (chunk) => {
        data += chunk;
      });

    req.on('end', () => {
        receive.push(JSON.parse(data))
        githubMessage()
        data = ''
      });

    res.writeHead(200);
    res.end();

}).listen(4200);


// client.on('ready', () => {
//     console.log(`Logged in as ${client.user.tag}!`);
//   });

// client.on('message', (msg) => {
    // if (msg.content === 'ping' || msg.content === 'ppng') {
    //     msg.reply("pong");
    //     msg.channel.send({embed: {
    //         color: 3447003,
    //         description: "A very simple Embed !!!!!"
    //      }});
    // }
//   });

// client.login('token du bot');
