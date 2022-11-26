-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT year, month, day, description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street'
AND description LIKE '%CS50%';

-- Theft took place around 10:15am in the Humphrey Street bakery.
-- Interviews with 3 witnesses

SELECT year, month, day, transcript
FROM interviews
WHERE month = 7 AND day = 28
AND transcript LIKE '%thief%';
"
Sometime within ten minutes of the theft,
I saw the thief get into a car in the bakery parking lot and drive away.
If you have security footage from the bakery parking lot,
you might want to look for cars that left the parking lot in that time frame.
"
"
I don't know the thief's name, but it was someone I recognized.
Earlier this morning, before I arrived at Emma's bakery,
I was walking by the ATM on Leggett Street and
saw the thief there withdrawing some money.
"
"
As the thief was leaving the bakery,
they called someone who talked to them for less than a minute.
In the call, I heard the thief say that they were planning
to take the earliest flight out of Fiftyville tomorrow.
The thief then asked the person on the other end of the phone
to purchase the flight ticket.
"

-- fligjts.id
SELECT flights.id, year, month, day, hour, minute, city
FROM flights
JOIN airports on airports.id = flights.destination_airport_id
JOIN passengers on passengers.flight_id = flights.id
WHERE month = 7 AND day = 29
ORDER BY hour, minute
LIMIT 1;
-- NYC

"
Trying to find persons in people table, needs 4 pieces of info:
    passport
    license plate
    phone number
    id
"
-- passport
SELECT flights.id, passport_number
FROM passengers
JOIN flights on passengers.flight_id = flights.id
WHERE flights.id IN
    (SELECT flights.id
    FROM flights
    JOIN airports on airports.id = flights.destination_airport_id
    JOIN passengers on passengers.flight_id = flights.id
    WHERE month = 7 AND day = 29
    ORDER BY hour, minute
    LIMIT 1);


-- license plates
SELECT year, month, day, hour, minute, activity, license_plate
FROM bakery_security_logs
WHERE month = 7 AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25
AND activity = 'exit';


-- phone numbers  (caller: Bruce, receiver: Robin)
SELECT year, month, day, duration, name, receiver
FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE month = 7 AND day = 28
AND duration <= 60;


-- id
SELECT person_id
FROM bank_accounts
WHERE account_number IN
    (SELECT account_number
    FROM atm_transactions
    WHERE month = 7 AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw');

-- SUSPECTS --

SELECT id, name
FROM people

-- passport
WHERE passport_number IN
    (SELECT passport_number
    FROM passengers
    JOIN flights on passengers.flight_id = flights.id
    WHERE flights.id IN
        (SELECT flights.id
        FROM flights
        JOIN airports on airports.id = flights.destination_airport_id
        JOIN passengers on passengers.flight_id = flights.id
        WHERE month = 7 AND day = 29
        ORDER BY hour, minute
        LIMIT 1)
    )

-- license plate
AND license_plate IN

    (SELECT license_plate
    FROM bakery_security_logs
    WHERE month = 7 AND day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25    -- important key: within 10 minutes after 10:15AM
    AND activity = 'exit')

-- phone number
AND phone_number IN

    (SELECT caller
    FROM phone_calls
    WHERE month = 7 AND day = 28
    AND duration <= 60)

-- id
AND id IN

    (SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
        (SELECT account_number
        FROM atm_transactions
        WHERE month = 7 AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw')
    );

"
| Bruce  |
"