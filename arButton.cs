using Firebase;
using Firebase.Database;
using Firebase.Unity.Editor;
using UnityEngine;

public class arButton : MonoBehaviour
{
    private Device s;
    private DatabaseReference dbReference;

    public void Start()
    {
        s = new Device("Appliance-1");
        FirebaseApp.DefaultInstance.SetEditorDatabaseUrl("https://ariot-5cdcc.firebaseio.com/");
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
