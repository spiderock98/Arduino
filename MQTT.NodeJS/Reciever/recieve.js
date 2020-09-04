const mqtt = require('mqtt')

const client = mqtt.connect('mqtt://localhost')

client.on('connect', () => {
    client.subscribe('garage')
    console.log('sub to broker');
})

client.on('message', (topic, message) => {
    if (topic === 'garage') {
        console.log(message.toString());
    }
})
