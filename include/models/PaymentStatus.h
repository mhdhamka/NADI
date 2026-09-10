#ifndef PAYMENTSTATUS_H
#define PAYMENTSTATUS_H

enum class PaymentStatus
{
    Pending,
    Processing,
    Completed,
    Failed,
    Cancelled,
    Refunded
};

#endif