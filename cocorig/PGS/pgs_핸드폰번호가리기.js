function solution(phone_number) {
  const phoneNumberLength = phone_number.slice(0 , -4).length;
  return '*'.repeat(phoneNumberLength) + phone_number.slice(-4);
}



