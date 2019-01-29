/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class edu_wpi_first_hal_AccelerometerJNI */

#ifndef _Included_edu_wpi_first_hal_AccelerometerJNI
#define _Included_edu_wpi_first_hal_AccelerometerJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     edu_wpi_first_hal_AccelerometerJNI
 * Method:    setAccelerometerActive
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_AccelerometerJNI_setAccelerometerActive
  (JNIEnv *, jclass, jboolean);

/*
 * Class:     edu_wpi_first_hal_AccelerometerJNI
 * Method:    setAccelerometerRange
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_edu_wpi_first_hal_AccelerometerJNI_setAccelerometerRange
  (JNIEnv *, jclass, jint);

/*
 * Class:     edu_wpi_first_hal_AccelerometerJNI
 * Method:    getAccelerometerX
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_AccelerometerJNI_getAccelerometerX
  (JNIEnv *, jclass);

/*
 * Class:     edu_wpi_first_hal_AccelerometerJNI
 * Method:    getAccelerometerY
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_AccelerometerJNI_getAccelerometerY
  (JNIEnv *, jclass);

/*
 * Class:     edu_wpi_first_hal_AccelerometerJNI
 * Method:    getAccelerometerZ
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_edu_wpi_first_hal_AccelerometerJNI_getAccelerometerZ
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
