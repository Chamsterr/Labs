import 'package:flutter_test/flutter_test.dart';
import 'package:mockito/mockito.dart';
import 'package:mockito/annotations.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:google_sign_in/google_sign_in.dart';
import 'mock_classes.mocks.dart';

@GenerateMocks([FirebaseAuth, GoogleSignIn, UserCredential])
void main() {
  group('LoginPage tests', () {
    late MockFirebaseAuth mockFirebaseAuth;
    late MockUserCredential mockUserCredential;

    setUp(() {
      mockFirebaseAuth = MockFirebaseAuth();
      mockUserCredential = MockUserCredential();
    });

    test('Successful login with email and password', () async {
      when(mockFirebaseAuth.signInWithEmailAndPassword(
          email: anyNamed('email'), password: anyNamed('password')))
          .thenAnswer((_) async => mockUserCredential);

      final result = await mockFirebaseAuth.signInWithEmailAndPassword(
        email: 'test@example.com',
        password: 'password123',
      );

      verify(mockFirebaseAuth.signInWithEmailAndPassword(
          email: 'test@example.com', password: 'password123')).called(1);

      expect(result, isA<UserCredential>());
    });

    test('Error during login with email and password', () async {
      when(mockFirebaseAuth.signInWithEmailAndPassword(
          email: anyNamed('email'), password: anyNamed('password')))
          .thenThrow(FirebaseAuthException(code: 'user-not-found'));

      try {
        await mockFirebaseAuth.signInWithEmailAndPassword(
          email: 'wrong@example.com',
          password: 'wrongpassword',
        );
      } catch (e) {
        expect(e, isA<FirebaseAuthException>());
        expect((e as FirebaseAuthException).code, 'user-not-found');
      }

      verify(mockFirebaseAuth.signInWithEmailAndPassword(
          email: 'wrong@example.com', password: 'wrongpassword')).called(1);
    });

    test('Successful password reset', () async {
      when(mockFirebaseAuth.sendPasswordResetEmail(email: anyNamed('email')))
          .thenAnswer((_) async => Future.value());

      await mockFirebaseAuth.sendPasswordResetEmail(email: 'test@example.com');

      verify(mockFirebaseAuth.sendPasswordResetEmail(
          email: 'test@example.com')).called(1);
    });
  });
}
