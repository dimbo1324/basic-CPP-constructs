### **Extracting Domain from URL**

`Extracting Domain from URL` is a minimalist C++ command-line tool that cuts through the noise and grabs just the domain portion out of any URL you throw at it. No fluff, no extra headers—just the core you need, lowercase and ready for whatever you’ve got planned next.

---

> **Why this exists**
> Because sometimes you only need the domain, not the whole messy path. Whether you’re logging referrers, normalizing input, or feeding a web-crawler, this tiny utility saves you time and brain cycles.

---

**Key Features**

* **Smart validation**: checks for a valid-looking URL (no spaces, must contain a “.”) and politely refuses to run on garbage.
* **Protocol-agnostic**: strips off `http://`, `https://` (or no protocol at all) before grabbing the host.
* **Path-trimmer**: stops at the first slash after the domain, so you never get unwanted path segments.
* **Case-insensitive output**: always returns the domain in lowercase—consistent, predictable, future-proof.
* **Zero dependencies**: pure C++17, standard library only. Clone, compile, run.

---

**Usage Example**

```bash
# Build
g++ -std=c++17 Extracter.cpp main.cpp -o extract_domain

# Run
./extract_domain "HTTPS://Site.com/PageOne"
# → prints: site.com
```