Microsoft Teams Federation Configuration

Scope: 1:1 chat and group chat only
Model: External access (federation)
Compliance alignment: ASD ISM, Microsoft best practice
Last validated: 06 February 2026

1. Purpose and Scope

This document defines the configuration required to enable Microsoft Teams federation for text-based 1:1 and group chat only, while preventing higher-risk collaboration features such as file sharing, channels, meetings, and application access.

The configuration is designed to:

Enable limited collaboration with external organisations

Maintain control over information exchange

Align with ASD ISM principles of least privilege and information containment

Avoid introducing unmanaged identities into the tenant

2. Federation Model Overview
What federation allows

1:1 chat between internal users and federated external users

Group chat (multi-party chat)

Optional presence visibility (risk-based)

What federation explicitly does not allow

SharePoint or OneDrive access

File transfer

Channel participation

Tenant resource access

External users signing into the tenant

Important: Federation is not guest access and does not create identities in the tenant.

3. Identity and Access Model (Corrected)
Conditional Access – Not Applicable

Conditional Access does not apply to Teams federation.

Federated users:

Authenticate entirely in their home Microsoft Entra ID tenant

Do not sign in to the agency tenant

Do not generate sign-in events evaluated by Conditional Access

As a result:

MFA, device compliance, location controls, and sign-in risk cannot be enforced by the agency on federated users

This is expected platform behaviour, not a configuration gap

Documented position (recommended wording)

“Conditional Access is not technically applicable to Microsoft Teams federation, as federated users authenticate in their home tenant and do not sign in to the agency’s Microsoft Entra ID. Risk is mitigated through service-level controls within Microsoft Teams, information protection mechanisms, and audit monitoring.”

4. Control Framework Used Instead of Conditional Access

Because identity-based enforcement is unavailable, risk is managed through service-level and information-level controls, as outlined below.

5. Microsoft Teams – External Access Configuration

Location: Teams admin center → Users → External access

Global settings
Setting	Configuration
External access	Enabled
Teams users can communicate with other Teams users	Enabled
Skype users	Disabled
Teams personal accounts	Disabled
Domain restrictions (strongly recommended)

Allow only specific external domains

Approved domains must be explicitly listed, for example:

partner1.gov.au
partner2.org


This aligns with ISM expectations to restrict external connectivity to known, approved entities.

6. Microsoft Teams – Messaging Policies (Primary Enforcement Point)

A custom messaging policy must be created and assigned to users who require federation access.

Chat controls
Setting	Value
Chat	Enabled
Private chat	Enabled
Group chat	Enabled
Read receipts	Optional
Giphy	Disabled
Stickers and memes	Disabled
URL previews	Optional
File and media controls (critical)
Setting	Value
Send files in chat	Disabled
Inline images	Disabled
Video messages	Disabled
Voice messages	Disabled

This prevents:

SharePoint and OneDrive invocation

Accidental or deliberate data transfer via chat

Meetings (recommended restriction)
Setting	Value
Schedule meetings	Disabled
Meet now	Disabled
External meetings	Disabled unless explicitly required
7. Microsoft Entra ID – External Collaboration Settings

Location: Entra admin center → External identities → External collaboration settings

Guest access
Setting	Configuration
Guest access	Disabled (preferred)
Guest permissions	Not applicable

Federation does not rely on guest access. Keeping this disabled avoids accidental expansion of access beyond chat.

8. Information Protection and Data Loss Prevention
Sensitivity labels

Classified or sensitive labels must block external sharing

Labels should apply to Teams content where supported

Higher classifications should explicitly prohibit external communication

DLP policies

DLP rules should monitor Teams chat for:

Sensitive personal information

Protected or classified keywords

Operational or regulatory data

Actions may include:

Block message

User warning

Audit and alerting

9. Logging, Monitoring, and Audit
Relevant audit sources
Area	Log Source
Teams chat activity	Microsoft Purview Audit
Federation events	Teams service logs
DLP violations	Purview DLP
Admin changes	Unified Audit Log
Retention

Minimum: 90 days

Recommended: 180–365 days

10. ASD ISM Alignment (Corrected)
ISM Principle	How Addressed
Least privilege	Chat-only federation
Information containment	No files, no media, no channels
Access governance	Domain allow-listing
Monitoring and detection	Audit logging and DLP
Risk management	Explicit acceptance of identity enforcement limitations

This approach aligns with ISM expectations where technical enforcement limits exist, provided compensating controls are applied and documented.

11. Explicit Limitations (Must Be Acknowledged)

The following limitations are inherent to the federation model:

Text content can be copied by external users

External tenant authentication strength cannot be enforced

Device posture and compliance cannot be validated

Controls apply only to outbound behaviour from the agency tenant

These limitations are accepted as part of the federation risk profile.

12. Governance Statement (Recommended for Approval Papers)

“Microsoft Teams federation is implemented as a constrained collaboration mechanism limited to text-based 1:1 and group chat. Conditional Access is not applicable due to the federated authentication model. Risk is mitigated through strict domain allow-listing, chat-only messaging policies, disabled file and media transfer, information protection controls, and audit monitoring, consistent with ASD ISM principles.”
