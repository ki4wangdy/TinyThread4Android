package com.ki4wangdy;

import com.example.testandroid.R;

import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity {

	public static final String TAG = "ki4wangdy";
	
	static {
		System.loadLibrary("tinyThread4Android");
		UnitTest.launchProducerAndConsumer();
//		UnitTest.launchSingelThread();
//		UnitTest.launchFastLock();
//		UnitTest.launchRecursiveLock();
//		UnitTest.launchLock();
	}
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}
}
