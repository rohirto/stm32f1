- Zephyr: Add USB CDC serial recovery check that now causes a build
  failure if console is enabled and device is the same as the USB
  CDC device.
- Zephyr: Add USB CDC serial recovery check that now causes a build
  failure if the main thread priority is below 0 (cooperative
  thread), this would prevent USB CDC from working as the driver
  would not have been able to fire callbacks.
