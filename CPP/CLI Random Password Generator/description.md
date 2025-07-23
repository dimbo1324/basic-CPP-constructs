### **CLI Random Password Generator**

**CLI Random Password Generator** is a sleek C++ utility that spins up a fortress‑worthy password in a single command. Feed it a spec like `<length><groups>` (e.g. `16abcd`), and it’ll pull from the character pools you choose to craft a random string that’s ready to lock down your accounts.

---

> **Why does it exist?**
> Because your time—and your security—matter. Instead of wrestling with online generators or scratching out passwords by hand, this tiny tool gives you a bulletproof keyphrase in one fell swoop.

---

**Key features:**

* **Flexible length & sets**: define exactly how many characters you want and which pools—uppercase (`a`), lowercase (`b`), digits (`c`), special (`d`)—to include.
* **Uniform distribution**: every character in your chosen pools has an equal chance of appearing, no bias, no weak spots.
* **Zero dependencies**: pure C++17, no external libraries required—just compile and go.
* **Built‑in validation**: rejects malformed input (e.g. no groups specified) with a clear error message.
* **Command‑line simplicity**: scriptable, automatable, perfect for devs who live in the terminal.

---

**Usage example:**

```bash
# Build:
g++ -std=c++17 main.cpp -o generator.exe

# Generate a 16‑character password with all groups:
./generator.exe 16abcd
# → Password: 7Gh!K2#mZpQ@x4Rt
```