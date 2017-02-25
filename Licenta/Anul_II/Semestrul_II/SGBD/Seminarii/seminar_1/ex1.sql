SELECT USERS.ID,
  COUNT(DISTINCT QUESTIONS.ID),
  QUESTIONS.USER_ID
FROM USERS
RIGHT JOIN QUESTIONS
ON USERS.ID = QUESTIONS.USER_ID
GROUP BY USERS.ID,
  QUESTIONS.USER_ID