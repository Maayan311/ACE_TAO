/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    MEM_IO.h
//
// = AUTHOR
//    Nanbor Wang <nanbor@cs.wustl.edu>
//
// ============================================================================

#ifndef ACE_MEM_IO_H
#define ACE_MEM_IO_H

#include "ace/SOCK.h"
#include "ace/MEM_SAP.h"
#include "ace/Memory_Pool.h"
#include "ace/Message_Block.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class ACE_Export ACE_MEM_IO : public ACE_SOCK, public ACE_MEM_SAP
{
  // = TITLE
  //     Defines the methods for the ACE shared memeory wrapper I/O
  //     routines (e.g., send/recv).
public:
  // = Initialization and termination methods.
  ACE_MEM_IO (void);
  // Constructor.

  ~ACE_MEM_IO (void);
  // Destructor.

  ssize_t send (const void *buf,
                size_t n,
                int flags) ;
  // Send an <n> byte buffer to the other process using shm_malloc_
  // connected thru the socket.

  ssize_t recv (void *buf,
                size_t n,
                int flags) ;
  // Recv an <n> byte buffer from the shm_malloc_ thru connected socket.

  ssize_t send (const void *buf,
                size_t n) ;
  // Send an <n> byte buffer to the other process using shm_malloc_
  // connected thru the socket.

  ssize_t recv (void *buf,
                size_t n) ;
  // Recv an <n> byte buffer from the shm_malloc_ thru connected socket.

  ssize_t fetch_recv_buf (int flags, const ACE_Time_Value *timeout = 0);
  // @@ Nanbor, please fill in here.

  ssize_t send (const void *buf,
                size_t n,
                int flags,
                const ACE_Time_Value *timeout);
  // Wait to to <timeout> amount of time to send up to <n> bytes into
  // <buf> from <handle> (uses the <send> call).  If <send> times out
  // a -1 is returned with <errno == ETIME>.  If it succeeds the
  // number of bytes sent is returned.

  ssize_t recv (void *buf,
                size_t n,
                int flags,
                const ACE_Time_Value *timeout);
  // Wait up to <timeout> amount of time to receive up to <n> bytes
  // into <buf> from <handle> (uses the <recv> call).  If <recv> times
  // out a -1 is returned with <errno == ETIME>.  If it succeeds the
  // number of bytes received is returned.

  ssize_t send (const void *buf,
                size_t n,
                const ACE_Time_Value *timeout);
  // Wait to to <timeout> amount of time to send up to <n> bytes into
  // <buf> from <handle> (uses the <send> call).  If <send> times out
  // a -1 is returned with <errno == ETIME>.  If it succeeds the
  // number of bytes sent is returned.

  ssize_t recv (void *buf,
                size_t n,
                const ACE_Time_Value *timeout);
  // Wait up to <timeout> amount of time to receive up to <n> bytes
  // into <buf> from <handle> (uses the <recv> call).  If <recv> times
  // out a -1 is returned with <errno == ETIME>.  If it succeeds the
  // number of bytes received is returned.

  ssize_t send (const ACE_Message_Block *message_block,
                const ACE_Time_Value *timeout);
  // Wait to to <timeout> amount of time to send the <message_block>.
  // If <send> times out a -1 is returned with <errno == ETIME>.  If
  // it succeeds the number of bytes sent is returned.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

  /*  int get_local_port (u_short &) const;
  // Return the local endpoint port number.  Returns 0 if successful,
  // else -1.

  int get_remote_port (u_short &) const;
  // Return the port number of the remotely connected peer (if there
  // is one). Returns 0 if successful, else -1.
  */
private:
  void *recv_buffer_;
  // Internal pointer for support recv/send.

  ssize_t buf_size_;
  // Total buffer size.

  ssize_t cur_offset_;
  // Current read pointer location.
};

#if !defined (ACE_LACKS_INLINE_FUNCTIONS)
#include "ace/MEM_IO.i"
#endif /* ACE_LACKS_INLINE_FUNCTIONS */

#endif /* ACE_SOCK_IO_H */
