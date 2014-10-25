void halt() //stops motor
{
  motorEn();
  digitalWrite(RPLUS,LOW);
  digitalWrite(RMINUS,LOW);
}

void motorEn() //enables the motor unlocking door
{
 analogWrite(REN, powerLevel);
}
