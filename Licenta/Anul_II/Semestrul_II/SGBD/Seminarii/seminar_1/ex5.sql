select USERS.* from USERS
  JOIN (
    select ID as ID, COUNT(REPORTS.ID) from REPORTS where REPORTS.USER_ID = USERS.ID
  ) m on USERS.id = M.id
    
;