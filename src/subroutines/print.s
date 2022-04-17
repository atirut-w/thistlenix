.ifndef _PRINT_S_
_PRINT_S_ = 1

.proc print
    lda $200, x
    cmp #0
    beq end
    sta $e003
    inx
    jmp print
end:
    rts
.endproc

.endif
