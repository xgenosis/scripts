## Secure Guest Access in Microsoft 365 with Access Packages, DLP, and Conditional Access (Cloud Apps Only)

This guide walks you through configuring **secure guest access** in Microsoft 365 using **Access Packages**, **Teams & SharePoint**, **DLP**, and **Conditional Access** locked to specific IPs. It applies to **web-only collaboration** (browser apps only) and **blocks guest 1:1 chats**, downloads, screenshots, and printing.

---

### ✅ Step 1: Enable Guest Access in Azure AD (Entra ID)
1. Go to **Entra ID** > **External Identities** > **External collaboration settings**.
2. Set the following:
   - **Guest invite settings**: Only admins and users in specified roles can invite.
   - **Guest user access restrictions**: Guest users have limited access.
3. Save.

---

### ✅ Step 2: Enable Guest Access in Teams
1. Go to **Teams Admin Center** > **Org-wide settings** > **Guest access**.
2. Toggle **Allow guest access in Teams** to **On**.
3. **Turn off guest Chat**:
   - Toggle **Chat** to **Off** (this blocks all 1:1 chats for guests).
4. Save.

---

### ✅ Step 3: Configure SharePoint and OneDrive for Guest Sharing
1. Go to **SharePoint Admin Center** > **Policies** > **Sharing**.
2. Set both SharePoint and OneDrive to:
   - **New and existing guests**.
3. Click **Save**.

---

### ✅ Step 4: Create a Teams Site for Collaboration
1. Create a **standard Team** in Microsoft Teams (do not use a private channel).
2. Example: Name it `External Collaboration – Org X`.
3. Add relevant members from your org.

---

### ✅ Step 5: Create a Dynamic Security Group for Guests
1. Go to **Entra ID** > **Groups** > **+ New Group**.
2. Group type: **Security**.
3. Name: `GuestUserSecurityGroup`.
4. Membership type: **Dynamic User**.
5. Add this rule:
   ```
   (user.userType -eq "Guest")
   ```
6. Create the group.

---

### ✅ Step 6: Create an Access Package
1. Go to **Entra ID** > **Identity Governance** > **Entitlement Management** > **Access packages**.
2. Create a **Catalog** (first time only):
   - Name: `External Collab Catalog`.
3. Click **+ New access package**.
4. Basics:
   - Name: `Guest Access – Org X`
   - Catalog: `External Collab Catalog`
5. **Resources**:
   - Add the Team created earlier.
   - Role: **Member**
6. **Requests**:
   - Who can request: **All users (All connected organizations)**
   - Add **Approver** (e.g. your internal team lead)
7. **Lifecycle**:
   - Expire: After 180 days
   - Access reviews: Every 90 days
8. Enable the access package.
9. Copy the access URL for onboarding.

---

### ✅ Step 7: Create a Sensitivity Label to Block Screenshots
1. Go to **Microsoft Purview** > **Information Protection** > **Labels** > **+ Create a label**.
2. Basics:
   - Name: `External Protect – View Only`
3. Set scope to **Items** (Files and Emails).
4. Enable encryption:
   - Assign permissions directly.
   - Add: `GuestUserSecurityGroup`
   - Permission: **View only**
   - Enable: **Block copy and print**, **Block screen capture**
5. Publish the label to `GuestUserSecurityGroup`.

---

### ✅ Step 8: Create a DLP Policy for Guests
1. Go to **Microsoft Purview** > **Data Loss Prevention** > **Policies**.
2. Click **+ Create Policy** > **Custom**.
3. Name: `External DLP – Block Downloads`
4. Locations:
   - Select the SharePoint site used by the Team
   - Enable for **Microsoft Teams chat & channel messages**
5. Conditions:
   - If content contains **any content**
6. Actions:
   - Block: **Download**, **Print**, **Copy**
   - Apply the Sensitivity Label: `External Protect – View Only`
7. User scope: `GuestUserSecurityGroup`
8. Notifications: On, no override
9. Save and publish

---

### ✅ Step 9: Apply Conditional Access for Guest IP Lockdown
1. Go to **Entra ID** > **Security** > **Named locations** > **+ New location**.
   - Name: `Partner Network Range`
   - Add IP range: e.g. `203.0.113.0/24`
2. Go to **Conditional Access** > **+ New policy**:
   - Name: `CA – Guests Web Only`
   - **Users**: Include `GuestUserSecurityGroup`
   - **Cloud Apps**: Include **Teams** and **SharePoint Online**
   - **Conditions**:
     - Locations > Include: `Partner Network Range`
   - **Grant**:
     - Require MFA
     - Require **Approved client app**
     - Use **Conditional Access App Control**
   - **Enable policy**: On
3. Save

---

### ✅ Step 10: Verification Checklist
- [ ] Guest redeems access package successfully
- [ ] Guest appears in Teams under "Members and guests"
- [ ] Guest can post in channels
- [ ] Guest **cannot** start private chats
- [ ] Guest cannot download or print content in browser
- [ ] Guest is prompted to use desktop app (if needed)
- [ ] Screenshots are blocked in desktop apps (if label applied)
- [ ] Guest sign-in blocked from non-approved IP
- [ ] Guest can join meetings from the Team

---

### 🔒 Notes & Best Practices
- Meeting invites must be generated via the Teams channel
- Consider watermarking content if concerned about photo capture
- Access reviews help ensure long-term hygiene
- Use separate private channels + access packages for smaller sub-teams

---

This setup ensures **external guests can only access defined sites**, cannot download or screenshot content, cannot 1:1 chat, and can only sign in from trusted locations.

Last updated: June 2025

