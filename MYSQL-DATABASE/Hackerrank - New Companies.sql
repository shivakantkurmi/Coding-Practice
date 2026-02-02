-- Link : https://www.hackerrank.com/challenges/the-company/problem?isFullScreen=true


SELECT 
    c.company_code,
    c.founder,
    COALESCE(lm.cnt, 0) AS lead_managers,
    COALESCE(sm.cnt, 0) AS senior_managers,
    COALESCE(m.cnt, 0) AS managers,
    COALESCE(e.cnt, 0) AS employees
FROM Company c
LEFT JOIN (
    SELECT company_code, COUNT(DISTINCT lead_manager_code) AS cnt
    FROM Lead_Manager
    GROUP BY company_code
) lm ON c.company_code = lm.company_code
LEFT JOIN (
    SELECT company_code, COUNT(DISTINCT senior_manager_code) AS cnt
    FROM Senior_Manager
    GROUP BY company_code
) sm ON c.company_code = sm.company_code
LEFT JOIN (
    SELECT company_code, COUNT(DISTINCT manager_code) AS cnt
    FROM Manager
    GROUP BY company_code
) m ON c.company_code = m.company_code
LEFT JOIN (
    SELECT company_code, COUNT(DISTINCT employee_code) AS cnt
    FROM Employee
    GROUP BY company_code
) e ON c.company_code = e.company_code
ORDER BY c.company_code;
