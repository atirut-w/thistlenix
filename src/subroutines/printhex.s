.ifndef _PRINTHEX_S_
_PRINTHEX_S_ = 1

.proc printhex
    pla
    sta return_addr
    pla
    sta return_addr+1

    pla
    tax

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

    lda return_addr+1
    pha
    lda return_addr
    pha
    rts

return_addr: .res 2
hexlookup: .byte "0123456789abcdef"
.endproc

.endif
