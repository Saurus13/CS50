-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT year FROM crime_scene_reports;
SELECT month, day FROM crime_scene_reports WHERE month = 07 AND day = 28;
SELECT month, day, street FROM crime_scene_reports WHERE month = 07 AND day = 28 AND street = "Humphrey Street";
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28;
SELECT transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

SELECT people.name, atm_transactions.transaction_type FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND atm_location = "Leggett Street" AND atm_transactions.transaction_type = "withdraw";