# Transcendence

Document and notes for learning this project

![Alt text](image.png)

### Final Version_1
```mermaid
graph TB
    %% Style definitions
    classDef external fill:#cccccc,stroke:#999999,color:#666666,stroke-width:2px
    classDef security fill:#BB3E03,stroke:#BB3E03,color:#fff,stroke-width:2px
    classDef frontend fill:#005F73,stroke:#005F73,color:#fff,stroke-width:2px
    classDef auth fill:#0A9396,stroke:#0A9396,color:#fff,stroke-width:2px
    classDef user fill:#94D2BD,stroke:#94D2BD,color:#000,stroke-width:2px
    classDef game fill:#E9D8A6,stroke:#E9D8A6,color:#000,stroke-width:2px
    classDef monitoring fill:#EE9B00,stroke:#EE9B00,color:#000,stroke-width:2px

    subgraph External["Third-Party Managed Services"]
        MobileWeb["Mobile Client"] --> CDN
        DesktopWeb["Desktop Client"] --> CDN
        TabletWeb["Tablet Client"] --> CDN
        CDN["CDN (e.g., Cloudflare)"]
    end
    
    CDN --> WAF["WAF :443"]

    subgraph Internal["Our Infrastructure"]
        subgraph Frontend Network
            NGINX["Nginx :80"]
            SPA["SPA :3000"]
            WAF --> NGINX
            NGINX --> SPA
        end

        subgraph Security Layer["Security Services"]
            Vault["HashiCorp Vault :8200"]
            TwoFA["2FA Service :8082"]
        end

        subgraph Auth Layer["Authentication Services"]
            NGINX --> OAuth["OAuth :8080"]
            OAuth --> AuthService["Auth Service :8001"]
            AuthService --> TwoFA
            AuthService --> AuthDB[("Auth DB :5432")]
            AuthService --> Vault
            class AuthDB auth
        end

        subgraph User Layer["User Management Services"]
            NGINX --> UserService["User Service :8002"]
            UserService --> UserProfileDB[("User Profile DB :5433")]
            UserService --> LeaderboardService["Leaderboard :8003"]
            LeaderboardService --> Redis[("Redis Cache :6379")]
            UserService --> Vault
            class UserProfileDB,Redis user
        end

        subgraph Game Layer["Game Services"]
            NGINX --> GameServer["Game Server :8004"]
            GameServer --> GameState["State Manager :8005"]
            GameServer --> MatchMaking["Matchmaking :8006"]
            GameState --> GameDB[("Game DB :5434")]
            MatchMaking --> MatchDB[("Match DB :5435")]
            GameServer --> Vault
            class GameDB,MatchDB game
        end

        subgraph Monitor["Monitoring Stack"]
            Prometheus["Prometheus :9090"] -.-> WAF & NGINX
            Prometheus -.-> AuthService & UserService & GameServer
            Prometheus -.-> TwoFA & Vault
            Grafana["Grafana :3001"] --> Prometheus

            WAF & NGINX -.-> Logstash["Logstash :5000"]
            AuthService & UserService & GameServer -.-> Logstash
            TwoFA & Vault -.-> Logstash
            Logstash --> Elasticsearch["ES :9200"]
            Elasticsearch --> Kibana["Kibana :5601"]

            CAdvisor["cAdvisor :8080"] -.-> WAF & NGINX & SPA
            CAdvisor -.-> AuthService & UserService & GameServer
            CAdvisor -.-> TwoFA & Vault
            CAdvisor -.-> Prometheus
        end
    end

    %% Apply styles
    class MobileWeb,DesktopWeb,TabletWeb,CDN external
    class WAF,Vault,TwoFA security
    class NGINX,SPA frontend
    class OAuth,AuthService auth
    class UserService,LeaderboardService user
    class GameServer,GameState,MatchMaking game
    class Prometheus,Grafana,Logstash,Elasticsearch,Kibana,CAdvisor monitoring
```

#### Flow with All Cybersecurity Modules

```mermaid
graph TD
    classDef user fill:#001219,stroke:#001219,color:#fff
    classDef security fill:#BB3E03,stroke:#BB3E03,color:#fff
    classDef service fill:#0A9396,stroke:#0A9396,color:#fff
    classDef data fill:#94D2BD,stroke:#94D2BD,color:#000

    subgraph "Initial Access Flow"
        User[Player] -->|1. HTTPS Request| WAF
        WAF[WAF] -->|2. Security Check| NGINX
        NGINX -->|3. Auth Request| Auth[Auth Service]
        Auth -->|4. 2FA Request| TwoFA[2FA Service]
        Auth -->|5. Get Secrets| Vault[HashiCorp Vault]
        
        TwoFA -->|6. Verify Code| Auth
        Auth -->|7. JWT Token| User
    end

    subgraph "Game Session Flow"
        User -->|8. WS Connection| WAF
        WAF -->|9. Inspect WS| WSGateway
        WSGateway -->|10. Validate Token| Auth
        WSGateway -->|11. Get Game Keys| Vault
        WSGateway -->|12. Establish WS| GameServer
    end

    subgraph "Database Access Flow"
        GameServer -->|13. Request Credentials| Vault
        Vault -->|14. Temp DB Creds| GameServer
        GameServer -->|15. Query| GameDB[(Game DB)]
    end

    %% Apply styles
    class User user
    class WAF,TwoFA,Vault security
    class NGINX,Auth,WSGateway,GameServer service
    class GameDB data
```

#### Flow explanation

```mermaid
graph TB
    %% Style definitions
    classDef client fill:#001219,stroke:#001219,color:#fff,stroke-width:2px
    classDef frontend fill:#005F73,stroke:#005F73,color:#fff,stroke-width:2px
    classDef gateway fill:#0A9396,stroke:#0A9396,color:#fff,stroke-width:2px
    classDef game fill:#94D2BD,stroke:#94D2BD,color:#000,stroke-width:2px
    classDef data fill:#E9D8A6,stroke:#E9D8A6,color:#000,stroke-width:2px

    subgraph Initial["Initial Load"]
        Browser["Browser"] --> NGINX
        NGINX --> SPA["SPA Bundle"]
        SPA --> InitialRender["Initial Game UI"]
    end

    subgraph GamePlay["Real-time Gameplay"]
        Browser2["Browser/Client"] -->|"1. WebSocket Connection"| WS["WebSocket Gateway"]
        
        %% Game events flow
        Browser2 -->|"2. Player Input\n(WS Message)"| GameServer
        GameServer -->|"3. Game State Update"| GameState
        GameState -->|"4. Broadcast State"| WS
        WS -->|"5. State Update"| Browser2
        
        %% Local state management
        Browser2 -->|"6. Local State\nUpdate"| LocalUI["Local Game UI"]
    end

    %% Apply styles
    class Browser,Browser2 client
    class NGINX,SPA,InitialRender,LocalUI frontend
    class WS gateway
    class GameServer,GameState game
```



### Draft version
```mermaid
graph TB
    subgraph Client Layer
        MobileWeb[Mobile Web] --> CDN
        DesktopWeb[Desktop Web] --> CDN
        TabletWeb[Tablet Web] --> CDN
        CDN[Content Delivery Network] --> NGINX
    end

    subgraph Frontend Stack
        NGINX[Nginx Reverse Proxy] --> SPA[Toolstrap Kit SPA]
        SPA --> I18N[I18N Service]
        SPA --> ThemeService[Theme Service]
        SPA --> ResponsiveService[Responsive Service]
        SPA --> AssetService[Asset Service]
    end

    subgraph Gateway Layer
        NGINX --> APIGateway[Django REST Framework]
        NGINX --> WSGateway[Django Channels]
    end

    subgraph CMS Layer
        APIGateway --> CMS[Django CMS]
        CMS --> ContentAPI[Django API]
        ContentAPI --> MediaService[Django Media Service]
    end

    subgraph Game Services
        WSGateway --> GameServer[Django Game Server]
        GameServer --> GameState[Game State Manager]
        GameServer --> MatchMaking[Matchmaking Service]
        GameServer --> ReplayService[Replay Service]
    end

    subgraph Core Services
        APIGateway --> AuthService[Django Auth]
        APIGateway --> UserService[Django User Service]
        APIGateway --> LeaderboardService[Leaderboard Service]
        APIGateway --> NotificationService[Django Channels Notifications]
    end

    subgraph Database Layer
        AuthService --> PostgreSQL[(PostgreSQL)]
        UserService --> PostgreSQL
        GameState --> PostgreSQL
        MatchMaking --> PostgreSQL
        ReplayService --> PostgreSQL
        CMS --> PostgreSQL
        LeaderboardService --> Redis[(Redis Cache)]
    end

    subgraph Observability Stack
        PostgreSQL & Redis & NGINX & APIGateway & WSGateway & GameServer --> Logstash
        Logstash --> Elasticsearch
        Elasticsearch --> Kibana
        
        Prometheus --> NGINX & APIGateway & WSGateway & GameServer
        Grafana --> Prometheus
    end
```

### Simplified version
```mermaid
graph TB
    %% Style definitions
    classDef clientLayer fill:#e6f3ff,stroke:#4a90e2,stroke-width:2px
    classDef frontendLayer fill:#fff2e6,stroke:#ff9933,stroke-width:2px
    classDef authLayer fill:#ffe6e6,stroke:#ff4d4d,stroke-width:2px
    classDef gatewayLayer fill:#e6ffe6,stroke:#47d147,stroke-width:2px
    classDef gameLayer fill:#f3e6ff,stroke:#9933ff,stroke-width:2px
    classDef userLayer fill:#fff0f5,stroke:#ff66b3,stroke-width:2px
    classDef dbLayer fill:#f2f2f2,stroke:#666666,stroke-width:2px
    classDef monitoringLayer fill:#e6fff2,stroke:#00cc66,stroke-width:2px

    subgraph Client Layer
        MobileWeb[Mobile Web] --> CDN
        DesktopWeb[Desktop Web] --> CDN
        TabletWeb[Tablet Web] --> CDN
        CDN[Content Delivery Network] --> NGINX
    end

    subgraph Frontend Stack
        NGINX[Nginx Reverse Proxy] --> SPA[Toolstrap Kit SPA]
    end

    subgraph Auth Layer
        NGINX --> OAuth[OAuth2.0 Provider]
        OAuth --> AuthService[Django Auth Service]
        AuthService --> AuthDB[(Auth DB)]
        OAuth --> ExternalOAuth[External OAuth Providers]
    end

    subgraph Gateway Layer
        NGINX --> APIGateway[Django REST Framework]
        NGINX --> WSGateway[Django Channels]
    end

    subgraph User Services
        APIGateway --> UserService[Django User Service]
        APIGateway --> LeaderboardService[Leaderboard Service]
        UserService --> UserDB[(User DB)]
        LeaderboardService --> Redis[(Redis Cache)]
    end

    subgraph Game Services
        WSGateway --> GameServer[Django Game Server]
        GameServer --> GameState[Game State Manager]
        GameServer --> MatchMaking[Matchmaking Service]
        GameState --> GameDB[(Game DB)]
        MatchMaking --> MatchDB[(Matchmaking DB)]
    end

    subgraph Monitoring Stack
        %% Prometheus monitors critical paths
        Prometheus --> NGINX
        Prometheus --> APIGateway
        Prometheus --> WSGateway
        Prometheus --> GameServer
        Prometheus --> UserService
        Prometheus --> LeaderboardService
        Prometheus --> GameDB
        Prometheus --> Redis
        Grafana --> Prometheus

        %% ELK Stack for detailed logging
        NGINX & APIGateway & WSGateway --> Logstash
        GameServer & GameState & MatchMaking --> Logstash
        UserService & LeaderboardService --> Logstash
        Logstash --> Elasticsearch
        Elasticsearch --> Kibana
    end

    %% Apply styles
    class MobileWeb,DesktopWeb,TabletWeb,CDN clientLayer
    class NGINX,SPA frontendLayer
    class OAuth,AuthService,ExternalOAuth authLayer
    class APIGateway,WSGateway gatewayLayer
    class GameServer,GameState,MatchMaking gameLayer
    class UserService,LeaderboardService userLayer
    class AuthDB,GameDB,MatchDB,UserDB,Redis dbLayer
    class Prometheus,Grafana,Logstash,Elasticsearch,Kibana monitoringLayer
```

### Detailed version
```mermaid
graph TB
    subgraph Client Layer
        MobileWeb[Mobile Web] --> CDN
        DesktopWeb[Desktop Web] --> CDN
        TabletWeb[Tablet Web] --> CDN
        CDN[Content Delivery Network] --> NGINX
    end

    subgraph Frontend Stack
        NGINX[Nginx Reverse Proxy] --> SPA[Toolstrap Kit SPA]
        SPA --> I18N[I18N Service]
        SPA --> ThemeService[Theme Service]
        SPA --> ResponsiveService[Responsive Service]
        SPA --> AssetService[Asset Service]
    end

    subgraph Auth Layer
        NGINX --> OAuth[OAuth2.0 Provider]
        OAuth --> AuthService[Django Auth Service]
        AuthService --> AuthDB[(Auth DB)]
        
        %% External OAuth providers
        OAuth --> Google[Google OAuth]
        OAuth --> GitHub[GitHub OAuth]
        OAuth --> Discord[Discord OAuth]
    end

    subgraph Gateway Layer
        NGINX --> APIGateway[Django REST Framework]
        NGINX --> WSGateway[Django Channels]
    end

    subgraph CMS Layer
        APIGateway --> CMS[Django CMS]
        CMS --> ContentAPI[Django API]
        ContentAPI --> MediaService[Django Media Service]
        CMS --> ContentDB[(CMS DB)]
        MediaService --> MediaDB[(Media DB)]
    end

    subgraph Game Services
        WSGateway --> GameServer[Django Game Server]
        GameServer --> GameState[Game State Manager]
        GameServer --> MatchMaking[Matchmaking Service]
        GameServer --> ReplayService[Replay Service]
        GameState --> GameDB[(Game DB)]
        MatchMaking --> MatchDB[(Matchmaking DB)]
        ReplayService --> ReplayDB[(Replay DB)]
    end

    subgraph User Services
        APIGateway --> UserService[Django User Service]
        APIGateway --> LeaderboardService[Leaderboard Service]
        APIGateway --> NotificationService[Django Channels Notifications]
        UserService --> UserDB[(User DB)]
        LeaderboardService --> Redis[(Redis Cache)]
        NotificationService --> NotifyDB[(Notification DB)]
    end

    subgraph Observability Stack
        %% Prometheus monitoring all services
        Prometheus --> SPA & OAuth & AuthService & APIGateway & WSGateway
        Prometheus --> CMS & ContentAPI & MediaService
        Prometheus --> GameServer & GameState & MatchMaking & ReplayService
        Prometheus --> UserService & LeaderboardService & NotificationService
        Prometheus --> AuthDB & ContentDB & MediaDB & GameDB & MatchDB & ReplayDB & UserDB & NotifyDB & Redis
        Grafana --> Prometheus

        %% Logging
        SPA & OAuth & AuthService & APIGateway & WSGateway --> Logstash
        CMS & ContentAPI & MediaService --> Logstash
        GameServer & GameState & MatchMaking & ReplayService --> Logstash
        UserService & LeaderboardService & NotificationService --> Logstash
        Logstash --> Elasticsearch
        Elasticsearch --> Kibana
    end
```