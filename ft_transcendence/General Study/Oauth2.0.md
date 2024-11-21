

### Authentication vs. authorization

Here's a quick overview of the differences between authentication and authorization:

|Authentication|    Authorization|
|--------------|-----------------|
|Determines whether users are who they claim to be |	Determines what users can and cannot access|
|Challenges the user to validate credentials (for example, through passwords, answers to security questions, or facial recognition) |	Verifies whether access is allowed through policies and rules|
|Usually done before authorization |	Usually done after successful authentication|
|Generally, transmits info through an ID Token |	Generally, transmits info through an Access Token|
|Generally governed by the OpenID Connect (OIDC) protocol |	Generally governed by the OAuth 2.0 framework|
|Example: Employees in a company are required to authenticate through the network before accessing their company email |	Example: After an employee successfully authenticates, the system determines what information the employees are allowed to access|

### Analogy of Oauth as Hotel checkin
|   |Hotel      |Oauth      |
|-------|-----------|-----------|
|ID check|Reception |Authorization Server|
|Access token|Room card|Access Token|
|Resource|Room, hotel facilities|Resource Server|

1. The reception(Authorization Server) do **Authentication** and check user ID and credentials.
2. Then, the reception give room card(access token) that grant **Authorizations** based on the identity of the user.
3. With the access token, user can have access to certain services that it is athorized without checking again the ID.


- Oauth issues **Access Tokens** to apps. The access token does not include user information.
- OpenID connect issues **ID Tokens** to apps. The ID Token is a state to the user.



### References

1. [Authentication vs authorization](https://auth0.com/docs/get-started/identity-fundamentals/authentication-and-authorization)
2. [Oauth 2.0 net](https://oauth.net/2/)