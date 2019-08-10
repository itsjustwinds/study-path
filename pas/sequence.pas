uses math;
type    th=set of 1..255;
var
        k,n,i,sum:longint;
        kq:int64;
        tt:th;
        a:array[1..300] of longint;
procedure nhap;
begin
        readln(n,k);
        for i:=1 to n do
                read(a[i]);
end;
procedure try(i,tong,tongkq:longint;t:th);
var     j,h,sum:longint;
        tt:th;
begin
        for j:=1 to n do
        if j in t then
        begin
                sum:=0;
                tt:=[];
                for h:=j to n do
                if h in t then
                begin
                        inc(sum,a[h]);
                        tt:=tt+[h];
                        if i=k then
                        begin
                                kq:=max(kq,tongkq+sum*(tong-sum));
                        end
                        else try(i+1,tong-sum,tongkq+sum*(tong-sum),t-tt);
                end;
        end;
end;
procedure xuly;
begin
        sum:=0;
        tt:=[];
        kq:=0;
        for i:=1 to n do
        begin
                inc(sum,a[i]);
                tt:=tt+[i];
        end;
        try(1,sum,0,tt);
        write(kq);
end;
begin
        assign(input,'sequence.inp');
        assign(output,'sequence.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.