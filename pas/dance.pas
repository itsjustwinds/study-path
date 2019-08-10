const
        fi='dance.inp';
        fo='dance.out';
type
        arr=array[0..100000] of longint;
var
        a1,a2,b1,b2:array[0..100000] of longint;
        n,i,g1,g2,t1,t2,x,j,d,vtt:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        g1:=0;g2:=0;t1:=0;t2:=0;
        for i:=1 to n do
        begin
                read(f,x);
                if x>0 then begin
                        inc(t2);
                        a2[t2]:=x;
                end
                else begin
                        inc(t1);
                        a1[t1]:=abs(x);
                end;
        end;
        for i:=1 to n do
        begin
                read(f,x);
                if x>0 then begin
                        inc(g2);
                        b2[g2]:=x;
                end
                else begin
                        inc(t1);
                        b1[t1]:=abs(x);
                end;
        end;
        close(f);
end;
procedure sort(var a:arr;l,r:longint);
var
        u,v,x,t:longint;
begin
        u:=l;v:=r;x:=a[(l+r) div 2];
        repeat
                while a[u]<x do inc(u);
                while a[v]>x do dec(v);
                if u<=v then
                begin
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if l<v then sort(a,l,v);
        if u<r then sort(a,u,r);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        sort(a1,1,t1);
        sort(a2,1,t2);
        sort(b1,1,g1);
        sort(b2,1,g2);
        i:=1;j:=1;d:=0;vtt:=1;
        repeat
                if j=t1 then
                begin
                        inc(i);
                        j:=vtt+1;
                end;
                if a1[i]<b2[j] then inc(j);
                  if a1[i]>b2[j] then begin
                        inc(d);
                        inc(i);
                        inc(j);
                        vtt:=j;
                  end;
        until (i=t1) and (j=g2);
        i:=1;j:=1;vtt:=1;
        repeat
                if j:=g2 then
                begin
                        inc(j);
                        i:=vtt+1;
                end;
                if b1[i]<a2[j] then inc(i);
                   if b1[i]>a2[j] then begin
                        inc(d);
                        inc(i);
                        inc(j);
                        vtt:=i;
                end;
        until (i=g1) and (j=t2);
        write(f,d);
     {   for i:=1 to t1 do
                write(f,a1[i],' ');
        writeln(f);
        for i:=1 to t2 do
                write(f,a2[i],' ');
        writeln(f);
        for i:=1 to g1 do
                write(f,b1[i],' ');
        writeln(f);
        for i:=1 to g2 do
                write(f,b2[i],' ');}
        close(f);
end;
begin
        nhap;
        xuly;
end.
