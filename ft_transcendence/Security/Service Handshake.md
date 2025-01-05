# Handshake between services

For services, like human being, to communicate to each other, you must be polite and say "Hello" to each other before you start talking!
This mechanism also makes sure that your target service (server) is ready to communicate. This is called `TCP Handshake` or `three-way handshake`

### TCP Handshake mechanism
Imangine *Client A* wants to talk to *Server B*.

1. Client A sends a "SYN" (synchronize) message to Server B
    - It includes a random sequence number to keep track of the conversation
    - Like sayig "Hey, can we talk?"
2. Server B responds with "SYN-ACK" (synchronize-acknowledge)
    - It acknowledges Client A's sequence number, and sends its own sequence number
    - Like saying "Yes, I heard you and I am ready to talk"
3. Client A sends and "ACK" (acknowledge")
    - It acknowledges Server B's sequence number.
    - Like saying "Alright, I am ready too. Let's start talking"

### Handshake with TLS (Transport Layer Security)
When we add TLS, things are getting complicated. It's now like two intelligent agents who don't know each other and try to communicate in public.

So first, when Client A finds someone is willing to talk (**TCP handshake**), he also needs to validate his ID (if he is our guy), and then use encrypted messages so only them can decrypt the messages they sent to each other.

1. Client A Hello
    - Client sends supported TLS versions
    - Lists supported encryption methods (cipher suites)
    - Sends a random number for generating keys later
    - Like saying "Hey, these are the languages (encryp methods) I know. Are you still able to talke to me encryptedly?"
2. Server B Hello
    - Server pickes TLS version and cipher suite
    - Sends its digital certificate
    - Sends its own random number
    - Like saying "Yes, I can also speak french. Let's talk in french. Here are my ID (certificate) and the material from me to generate keys later (random number).
3. Certificate Verification
    - Client verifies server's certificate with a trusted authority
    - Like checkiing someone's ID and see if the ID is signed by their government (trusted authority)
4. Key Exchange
    - Client generates a "pre-master secret".
    - Client encrypts the secret with server's public key and send it to server
    - Like saying "Okay, ID verified. I am sending you a material locked in a box that you already had the key to open. This material will be used for our communication encryption later"
5. Session Keys Creation
    - Both client and server now have two random numbers and a "pre-master secret"
    - They use these three material to create indentical **sessioin keys** independently using the encryption method the sever picked before.
6. Ready to communicate
    - Both sides say "Okay, let's switch to encrypted communication"
    - All the further messages will be encrypted with session keys.