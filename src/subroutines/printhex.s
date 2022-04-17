.ifndef _PRINTHEX_S_
_PRINTHEX_S_ = 1

.proc printhex

.segment "RODATA"

hexlookup:
    .byte "0123456789ABCDEF"

.segment "CODE"
    txa
    and #$f0

    lsr
    lsr
    lsr
    lsr

    tay
    lda hexlookup,y
    sta $e003

    txa
    and #$0f
    tay
    lda hexlookup,y
    sta $e003

    rts

.endproc

.endif
