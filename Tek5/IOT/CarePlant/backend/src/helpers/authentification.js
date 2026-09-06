const crypto = require('crypto');

exports.Bearer = (email, password) => {
    return crypto.createHash('md5').update(email + password).digest('hex')
}
