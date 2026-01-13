Risk Assessment Paper — Teams Federation (Selected Gov Departments) — Chat Only

Document owner: <Branch/Section>
Service: Microsoft Teams (External Access / Federation)
Date: <DD MMM YYYY>
Decision requested: Endorse enabling Teams external chat with a small set of allowlisted government departments, for chat only.

1) What we’re trying to achieve

We want to support day-to-day collaboration with nominated Australian Government departments by enabling Teams chat (primarily 1:1). This provides a quick, auditable way for staff to communicate with trusted government counterparts without opening broader collaboration features.

Included: 1:1 chat, presence/availability, basic user profile display.
Not included: file sharing in chat, external Teams meetings, guest access to Teams/Sites, SharePoint/OneDrive external sharing expansion, open federation to non-allowlisted domains.

2) Key assumptions

Partner departments operate with appropriate identity protections (at minimum MFA and monitoring).

Our environment has standard monitoring and compliance capabilities in place (audit logging, endpoint security, and information protection controls).

We will use an allowlist-only approach (federation is only available to approved government domains).

3) What could go wrong (and why it matters)
Risk ID	Scenario	Likelihood	Impact	Inherent risk
R1	Someone accidentally shares sensitive information in an external chat	Med	High	High
R2	External chat is used for phishing or social engineering	High	High	High
R3	Links lead users to malicious content or downloads	Med	High	High
R4	A compromised account is used to communicate externally	Med	High	High
R5	We can’t easily find/review records when needed (investigation/eDiscovery/FOI)	Med	Med	Med
R6	Misconfiguration unintentionally expands access beyond “chat only”	Low-Med	High	Med-High
4) How we will manage the risk (controls)

Keep federation tightly scoped

Enable external access only for allowlisted government domains (no open federation).

Configure federation to be chat-only:

Block file transfer pathways in chat (and ensure SharePoint/OneDrive external sharing settings don’t introduce a backdoor).

Disable or restrict external meetings (kept out of scope unless separately approved).

Strong identity controls (Essential Eight aligned)
3. Enforce MFA for all users; prefer stronger methods for privileged roles. (E8: MFA)
4. Use Conditional Access for Teams/M365 to require:

compliant/managed devices (Intune) or approved client apps

modern authentication only

sign-in risk controls (where available)

Limit who can change external access settings using least privilege, with PIM for elevation. (E8: Restrict admin privileges)

Protect endpoints and reduce link-based risk
6. Ensure Defender for Endpoint protections are in place (web protection/ASR rules as applicable).
7. Use link protection (e.g., Safe Links or equivalent) to help identify and block suspicious URLs.
8. Where licensed, apply Purview DLP for Teams chat to reduce the chance of sensitive data being sent externally.

Logging, retention, and oversight
9. Confirm Unified Audit Log is enabled and monitored for unusual external chat activity.
10. Apply an appropriate Teams chat retention policy aligned to recordkeeping requirements.
11. Use change control and regular review: quarterly review of allowlisted domains, policy configuration, and any alerts/incidents.

5) Residual risk (after controls are applied)
Risk ID	Residual rating	Notes
R1	Medium	Reduced via DLP/labels/training; user error can’t be eliminated entirely.
R2	Medium	Strongly reduced via MFA/CA/monitoring; still a common attack vector.
R3	Low-Med	Reduced via link protection + endpoint controls.
R4	Low-Med	Reduced via MFA/CA/PIM; depends on consistent enforcement.
R5	Low	Audit + retention provides good investigative coverage.
R6	Low	Scoping + least privilege + change control reduces likelihood.

Overall residual risk: Medium (appropriate for a scoped, allowlisted “chat only” use case with the above safeguards).

6) Essential Eight alignment (practical summary)

MFA: enforced for all users, stronger for privileged roles.

Restrict admin privileges: RBAC + PIM for configuration changes.

Patch OS / apps: enforced via Intune compliance and update management.

Application control: WDAC / App Control (where implemented) reduces malicious execution paths.

Hardening: endpoint protection and web/link controls reduce exposure from malicious content.

Backups: not directly a federation control, but complements organisational resilience; retention supports chat record needs.

7) Recommendation

Approve enabling Teams federation for chat only with allowlisted government domains, provided the controls above are implemented and reviewed on a regular basis.

Proactive recommendation

Create a simple “External chat do’s and don’ts” one-pager for staff (what’s okay to share, what isn’t, and how to report suspicious messages).

Stand up a standard configuration baseline so any future additions of departments follow the same guardrails (and don’t become ad-hoc exceptions).

If you want, paste the list of partner domains (or just how many departments you’re allowlisting) and I’ll tweak the wording to include an “Approval scope” line that reads cleanly in an exec pack.
