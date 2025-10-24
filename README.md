# eBPF bpftrace Open/Close Syscall Frequency Tracer

This project contains a simple eBPF program written in `bpftrace` that traces the frequency of `open` and `close` system calls made by a process on a Linux system.

## Overview

The provided `bpftrace` script attaches to kernel tracepoints for `sys_enter_openat` and `sys_enter_close` to monitor when those syscalls are invoked. It keeps a count of how many times each syscall is called by processes, indexed by their PID and command name.
