from firebase_admin import db, credentials
import firebase_admin

cred = credentials.Certificate('service_key.json')

firebase_admin.initialize_app(cred, {
    'databaseURL' : 'https://ariot-5cdcc.firebaseio.com/'
})

root = db.reference()
print(root.get())
root.update({'Appliance-1':'OFF','Appliance-2':'ON'})
print(root.get())

