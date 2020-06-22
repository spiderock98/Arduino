const mqtt = require('mqtt')

const client = mqtt.connect('mqtt://localhost')

client.on('connect', () => {
    client.publish('garage', 'hello subscribers')
    console.log('pub to broker')
})
