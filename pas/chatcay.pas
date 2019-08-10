uses math;
var
        c,v,kq,tong:array[0..1001] of int64;
        tg:array[0..1001] of real;
        w,max:int64;
        i,j,vt,n:longint;
procedure nhap;
begin

        readln(n,w);
        for i:=1 to n do
                readln(v[i],c[i]);
end;
procedure sort(l,r:longint);
var
        i,j,x,t:longint;
begin
        i:=l;j:=r;x:=c[(l+r) div 2];
        repeat
                while c[i]>x do inc(i);
                while c[j]<x do dec(j);
                if i<=j then
                begin
                        t:=c[i];c[i]:=c[j];c[j]:=t;
                        t:=v[i];v[i]:=v[j];v[j]:=t;
                        inc(i);dec(j);
                end;
        until i>j;
        if l<j then sort(l,j);
        if i<r then sort(i,r);
end;
procedure xuly;
begin
        sort(1,n);
        kq[0]:=0;
        tong[0]:=0;
        for i:=1 to n do
        begin
                kq[i]:=kq[i-1]+c[i];
                tong[i]:=tong[i-1]+v[i];
        end;
        max:=0;
        for i:=1 to n do
                for j:=0 to i-1 do
                if (tong[i]-tong[j]<=w) and (kq[i]-kq[j]>max) then
                begin
                        max:=kq[i]-kq[j];
                        break;
                end;
        write(max);
end;

 ///////////////////////////////////////////////////////////////// cach 2
{procedure sort(l,r:longint);
var     i,j,t:longint;
        x:real;
begin
        i:=l;j:=r;x:=tg[(l+r) div 2];
        repeat
                while tg[i]>x do inc(i);
                while tg[j]<x do dec(j);
                if i<=j then
                begin
                        t:=c[i];c[i]:=c[j];c[j]:=t;
                        t:=v[i];v[i]:=v[j];v[j]:=t;
                        inc(i);dec(j);
                end;
        until i>j;
        if l<j then sort(l,j);
        if i<r then sort(i,r);
end;
procedure xuly;
var     sum:longint;
begin
        for i:=1 to n do
                tg[i]:=c[i]/v[i];
        sort(1,n);
        max:=0;
        sum:=0;
        for i:=1 to n do
                if sum+v[i]<=w then
                begin
                        sum:=sum+v[i];
                        max:=max+c[i];
                end;
        write(max);
end;    }
/////////////// ///////////////////////////////////////////////////
begin
        assign(input,'chatcay.inp');
        assign(output,'chatcay.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.