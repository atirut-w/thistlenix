.ifndef _COMPONENT_S_
_COMPONENT_S_ = 1

; Component-related subroutines, mostly wrappers for the component mapper.
; See: https://github.com/gamax92/Thistle/wiki/Component-Mapper

.include "errno.s"

.segment "CODE"

.scope component

.proc get_count
    lda #3
    sta $e010

    lda $e010
    cmp #0
    bne error

    ldx $e011
    rts
error:
    lda #EIO
    sta errno
    rts
.endproc

.endscope

.endif
