using Firebase;
using Firebase.Database;
using Firebase.Unity.Editor;
using UnityEngine;

// Class to handle event handler 
public class arButton : MonoBehaviour
{
    private Device s;

    // Databse reference object 
    private DatabaseReference dbReference;

    public void Start()
    {
        s = new Device("Appliance-1");
        FirebaseApp.DefaultInstance.SetEditorDatabaseUrl("https://ariot-5cdcc.firebaseio.com/");
        // Root reference of the database 
        dbReference = FirebaseDatabase.DefaultInstance.RootReference;
    }

    public void onButton()
    {   
        s.setSwitchON();
        dbReference.Child(s.getName()).SetValueAsync(s.getSwitch());
    }

    public void offButton()
    {
        s.setSwitchOFF();
        dbReference.Child(s.getName()).SetValueAsync(s.getSwitch());

    }

}
