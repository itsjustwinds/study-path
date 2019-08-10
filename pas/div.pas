const
        fi='div.inp';
        fo='div.out';
var
        a,s:array[0..1000] of longint;
        dd:array[0..1000]of longint;
        i,n,k,p:longint;
        f,g:text;
procedure xuly;
var     i,t:longint;
        kq:int64;
begin
        dd[0]:=1;
        s[0]:=0;
        kq:=0;
        for i:=1 to n do
        begin
                s[i]:=s[i-1]+a[i];
                t:=s[i] mod p;
                        if (dd[t]<>0) then
                        begin
                                kq:=kq+dd[t];
                                inc(dd[t]);
                        end;
                if dd[t]=0 then inc(dd[t]);
        end;
        writeln(g,kq);
end;
procedure nhap;
var i,j:longint;
begin
        assign(f,fi);
        assign(g,fo);
        reset(f);
        rewrite(g);
        readln(f,k);
        readln(f,p,n);
        for i:=1 to k do
        begin
                fillchar(dd,sizeof(dd),0);
                for j:=1 to n do
                        read(f,a[j]);
                xuly;
        end;
        close(f);
        close(g);
end;
begin
        nhap;
end.
