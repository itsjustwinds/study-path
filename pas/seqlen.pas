const
        fi='seqlen.inp';
        fo='seqlen.out';
var
        a:array [1..18] of int64;
        n,d,n1:int64;
        f:text;
        i,dems:longint;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function dem(k:int64):int64;
begin
        dem:=0;
        while k<>0 do
        begin
                inc(dem);
                k:=k div 10;
        end;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);d:=0;
        a[1]:=9;
        for i:=2 to dem(n) do
                a[i]:=a[i-1]*10;
        i:=1;
        repeat
                if n-a[i]>=0 then
                begin
                        d:=d+a[i]*i;
                        n:=n-a[i];
                end
                else begin
                        d:=d+i*n;
                        n:=0;
                     end;
                inc(i);
        until n=0;
        write(f,d);
        close(f);
end;
begin
        nhap;
        xuat;
end.
