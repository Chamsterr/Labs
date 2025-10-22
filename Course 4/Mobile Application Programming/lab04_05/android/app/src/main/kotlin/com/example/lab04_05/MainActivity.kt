package com.example.lab04_05

import android.os.Bundle
import io.flutter.embedding.android.FlutterActivity
import io.flutter.plugin.common.MethodChannel
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import android.content.Context

class MainActivity: FlutterActivity(), SensorEventListener {

    private lateinit var sensorManager: SensorManager
    private var accelerometerValues: FloatArray = FloatArray(3)

    private val CHANNEL = "com.example.accelerometer/accelerometer"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Инициализация сенсора акселерометра
        sensorManager = getSystemService(Context.SENSOR_SERVICE) as SensorManager
        val accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)
        sensorManager.registerListener(this, accelerometer, SensorManager.SENSOR_DELAY_NORMAL)

        // Регистрация MethodChannel для обработки вызова из Flutter
        MethodChannel(flutterEngine?.dartExecutor?.binaryMessenger, CHANNEL).setMethodCallHandler { call, result ->
            if (call.method == "getAccelerometer") {
                result.success(accelerometerValues.toList()) // Возвращаем данные акселерометра
            } else {
                result.notImplemented()
            }
        }
    }

    override fun onSensorChanged(event: SensorEvent?) {
        if (event?.sensor?.type == Sensor.TYPE_ACCELEROMETER) {
            accelerometerValues = event.values.clone() // Обновляем данные акселерометра
        }
    }

    override fun onAccuracyChanged(sensor: Sensor?, accuracy: Int) {
        // Можно игнорировать
    }

    override fun onDestroy() {
        super.onDestroy()
        sensorManager.unregisterListener(this) // Отключаем прослушивание при уничтожении Activity
    }
}
