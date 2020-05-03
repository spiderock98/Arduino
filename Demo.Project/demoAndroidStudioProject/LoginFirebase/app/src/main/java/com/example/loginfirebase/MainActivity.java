package com.example.loginfirebase;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Parcelable;
import android.provider.Settings;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;

public class MainActivity extends AppCompatActivity {

    FirebaseAuth mAuth;

    ImageView img;
    EditText txtUser, txtPass;
    Button btnSign, btnLog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

//        android.provider.Settings.System.putInt(getContentResolver(), Settings.System.SCREEN_OFF_TIMEOUT, 120000);

        mAuth = FirebaseAuth.getInstance();

        txtUser = (EditText) findViewById(R.id.txtUser);
        txtPass = (EditText) findViewById(R.id.txtPass);
        btnSign = (Button) findViewById(R.id.btnSign);
        btnLog = (Button) findViewById(R.id.btnLog);

        btnLog.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String _id = txtUser.getText().toString();
                String _pass = txtPass.getText().toString();
                if (_id.isEmpty() || _pass.isEmpty()){
                    Toast.makeText(MainActivity.this, "Fill the username and password", Toast.LENGTH_SHORT).show();
                }
                else{
                    mAuth.signInWithEmailAndPassword(_id, _pass).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
                        @Override
                        public void onComplete(@NonNull Task<AuthResult> task) {
                            FirebaseUser currentUser = mAuth.getCurrentUser();
                            if (task.isSuccessful() && currentUser != null){
                                Log.d("TAG", "onComplete: " + currentUser.getUid());
                                Toast.makeText(MainActivity.this, "Successfully Login", Toast.LENGTH_SHORT).show();

                                Intent intentCurrentUser = new Intent(MainActivity.this, home.class);
//                                intentCurrentUser.putExtra("currentUser", (Parcelable) task);

                                startActivity(intentCurrentUser);
                            }
                            else
                                Toast.makeText(MainActivity.this, task.getException().toString(), Toast.LENGTH_LONG).show();
                        }
                    });
                }
            }
        });
    }
    @Override
    public void onStart() {
        super.onStart();
        // Check if user is signed in (non-null) and update UI accordingly.
        FirebaseUser currentUser = mAuth.getCurrentUser();
    }
}