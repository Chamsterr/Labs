const nm = require("nodemailer");

function send(sender, password, receiver, message) {``
    let transporter = nm.createTransport(
        {
            host: 'smtp-mail.outlook.com',
            port: 587,
            secure: false,
            auth: {
                user: sender,
                pass: password
            }
        }
    );

    var mailOptions = {
        from: sender,
        to: receiver,
        subject: 'Lab5',
        text: message,
    };

    transporter.sendMail(mailOptions, (error, info) => {
        error ? console.log(error) : console.log('Email sent: ' + info.response);
    })
};

module.exports = send;