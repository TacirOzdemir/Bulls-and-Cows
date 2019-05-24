# Bulls and Cows

C++ word-guessing game using Qt and ZeroMQ.

![Logo](https://raw.githubusercontent.com/TacirOzdemir/Bulls-and-Cows/master/BullsCows_Logo.png)

There are three main components; Broker, Client and Server.

1. Client connects to the Broker
2. Client requests IP of Server from Broker
3. Server uses WIMIP to respond to request via Broker
4. Broker sends IP to Client
5. Client connects to Server
6. Client sends word request to Server
7. Server responds with hidden word
8. Client plays game

![Bulls_Cows_ZMQ.png](https://raw.githubusercontent.com/TacirOzdemir/Bulls-and-Cows/master/Bulls_Cows_ZMQ.png)

Player tries to guess the hidden word.

If a letter is correct but at the wrong spot, the Cow count is increased.

If a letter is correct and at the right spot, the Bull count is increased.

Player wins if the word is guessed correctly.

Player loses if there are no more tries left.

Amount of tries depends on the length of the hidden word.
