IMPLEMENTATION STEPS
STEP 1 — Microsoft Teams Admin Center
Enable External Access (Federation)

Portal:
Teams admin center
https://admin.teams.microsoft.com

Navigation:
Users → External access

Actions

Open Teams admin center

Navigate to Users → External access

Set External access to On

Set Teams users can communicate with other Teams users to On

Set Skype users to Off
Set Teams personal (consumer) accounts to Off
Click Save

Expected Result

Federation is enabled only for organisational Teams tenants

Consumer and Skype identities are blocked

Evidence to Capture (ServiceNow)

Screenshot of External access page showing settings

STEP 2 — Microsoft Teams Admin Center
Restrict Federation to Approved Domains

Portal:
Teams admin center

Navigation:
Users → External access

Actions

In External access, locate Domain restrictions

Select Allow only specific external domains

Add each approved external domain individually (example):

partner1.gov.au
partner2.org


Confirm no wildcard domains are used

Click Save

Expected Result

Federation is restricted to explicitly approved partner organisations

All other external domains are blocked by default

Evidence to Capture

Screenshot showing domain allow list

STEP 3 — Microsoft Teams Admin Center
Create Chat-Only Messaging Policy

Portal:
Teams admin center

Navigation:
Messaging policies

Actions

Navigate to Messaging policies

Click Add

Create a new policy with:

Name: Federation-Chat-Only

Description: Chat-only policy for federated users

Configure the following settings:

Chat Settings

Chat: On

Private chat: On

Group chat: On

Read receipts: Optional (risk-based)

Giphy: Off

Stickers and memes: Off

URL previews: Optional

Click Save

Expected Result

Chat is enabled, but limited to text-based interactions

Evidence to Capture

Screenshot of policy settings

STEP 4 — Microsoft Teams Admin Center
Disable File, Media, and Rich Content in Chat

Portal:
Teams admin center

Navigation:
Messaging policies → Federation-Chat-Only

Actions

Edit the Federation-Chat-Only policy

Set the following:

File and Media Controls

Send files in chat: Off

Inline images: Off

Video messages: Off

Voice messages: Off

Click Save

Expected Result

File transfer via SharePoint/OneDrive is prevented

Media-based data leakage is blocked

Evidence to Capture

Screenshot showing file/media disabled

STEP 5 — Microsoft Teams Admin Center
Disable Meetings for Federated Users (Recommended)

Portal:
Teams admin center

Navigation:
Messaging policies → Federation-Chat-Only

Actions

In the same policy, locate Meetings

Configure:

Schedule meetings: Off

Meet now: Off

Participate in meetings with external users: Off (unless explicitly approved)

Click Save

Expected Result

Federation is limited to chat only

No meeting escalation path exists

Evidence to Capture

Screenshot of meeting settings

STEP 6 — Microsoft Teams Admin Center
Assign Messaging Policy to Users

Portal:
Teams admin center

Navigation:
Users → Manage users

Actions

Identify users requiring federation

Select user(s)

Assign Messaging policy = Federation-Chat-Only

Confirm assignment

Expected Result

Only approved users can initiate federated chat

Policy is not tenant-wide unless explicitly approved

Evidence to Capture

Screenshot of user policy assignment

STEP 7 — Microsoft Entra Admin Center
Confirm Guest Access Is Disabled

Portal:
Microsoft Entra admin center
https://entra.microsoft.com

Navigation:
External identities → External collaboration settings

Actions

Open External collaboration settings

Confirm Guest access is Disabled (preferred)

Confirm no automatic guest invitations are enabled

Save if changes are made

Expected Result

Federation operates independently of guest access

No unintended SharePoint or Teams resource access

Evidence to Capture

Screenshot of guest access settings

STEP 8 — Microsoft Purview
Confirm Audit Logging Is Enabled

Portal:
Microsoft Purview portal
https://compliance.microsoft.com

Navigation:
Audit

Actions

Confirm Unified Audit Log is enabled

Verify logging for:

Teams chat activity

External access configuration changes

Confirm retention meets agency standard (≥90 days)

Expected Result

Federated chat activity is auditable

Administrative changes are logged

Evidence to Capture

Screenshot showing audit enabled / retention settings

STEP 9 — Microsoft Purview
Validate DLP Coverage for Teams Chat

Portal:
Microsoft Purview portal

Navigation:
Data loss prevention → Policies

Actions

Confirm DLP policies apply to Microsoft Teams chat

Validate detection for:

Sensitive personal information

Agency-defined sensitive keywords

Confirm actions:

Block or warn

Audit event generated

Expected Result

Content-based controls compensate for lack of CA

Policy violations are visible and actionable

Evidence to Capture

Screenshot of DLP policy scope

STEP 10 — Documentation and Acceptance (Mandatory)

Location:
ServiceNow change record / risk register
