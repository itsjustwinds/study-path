var
        t,n,r,l,i,j:longint;
        f:ansistring;
          a:array[1..100000] of ansistring;
function tong(a,b:ansistring):ansistring;
var     x,i:longint;
        kq:ansistring;
        nho:longint;
begin
        while length(a)<>length(b) do
        begin
                if length(a)<length(b) then a:='0'+a
                else b:='0'+b;
        end;
        nho:=0;
        kq:='';
        for i:=length(a) downto 1 do
        begin
                x:=ord(a[i])+ord(b[i])-96+nho;
                nho:=x div 10;
                kq:=chr(x mod 10+48)+kq;
        end;
        if nho>0 then kq:='1'+kq;
        exit(kq);
end;
procedure xuly;
var     kt:boolean;
        i,j,k:longint;
        s:ansistring;
begin
        kt:=false;
        for i:=l to r do
        begin
                if kt then break;
                for j:=i to r do
                begin
                        str(i,s);
                        a[1]:=s;
                        str(j,s);
                        a[2]:=s;
                        for k:=3 to n do
                                a[k]:=tong(a[k-1],a[k-2]);
                        if a[n]=f then
                        begin
                                kt:=true;
                                break;
                        end;
                end;
        end;
        if kt then writeln('YES')
        else writeln('NO');
end;
procedure nhap;
begin
        readln(t);
        for i:=1 to t do
        begin
                readln(n,l,r);
                readln(f);
                xuly;
        end;
end;
begin
        assign(input,'lrf.inp');
        assign(output,'lrf.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
