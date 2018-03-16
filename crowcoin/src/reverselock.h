// Copyright (c) 2015 The Crowcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CROWCOIN_REVERSELOCK_H
#define CROWCOIN_REVERSELOCK_H

/**
 * An RAII-style reverse lock. Unlocks on construction and locks on destruction.
 */
template<typename Lock>
class reverse_lock
{
public:

    explicit reverse_lock(Lock& lock) : lock(lock) {
        lock.unlock();
    }

    ~reverse_lock() {
        lock.lock();
    }

private:
    reverse_lock(reverse_lock const&);
    reverse_lock& operator=(reverse_lock const&);

    Lock& lock;
};

#endif // CROWCOIN_REVERSELOCK_H
