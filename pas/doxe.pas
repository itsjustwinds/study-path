const
        fi='doxe.inp';
        fo='doxe.out';
var
        d,c:array [1..3] of longint;
        x,y,z,t,ctn,cth,i,ccn:longint;
        kt:boolean;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,x,y,z);
        for i:=1 to 3 do
                readln(f,d[i],c[i]);
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v,x,t:longint;
begin
        u:=l;v:=r;x:=d[(l+r) div 2];
        repeat
                while d[u]<x do inc(u);
                while d[v]>x do dec(v);
                if u<=v then
                begin
                        t:=d[u];d[u]:=d[v];d[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if u<r then sort(u,r);
        if l<v then sort(l,v);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        sort(1,3);
        ctn:=0;ccn:=0;cth:=0;
        i:=1;
                if (c[i]<c[i+1]) and (c[i]<c[i+2]) then
                begin
                        ctn:=c[i];
                        if c[i+1]<c[i+2] then begin
                                                        cth:=c[i+1];
                                                        ccn:=c[i+2];
                                              end
                        else begin
                        cth:=c[i+2];
                        ccn:=c[i+1];
                        end;
                end;

                if (c[i+1]<c[i]) and (c[i+1]<c[i+2]) then
                begin
                        ctn:=c[i+1];
                        if c[i]<c[i+2] then begin
                                cth:=c[i]  ;
                                ccn:=c[i+2];
                        end
                        else     begin
                        cth:=c[i+2];
                        ccn:=c[i];
                end;
                end;
                 if (c[i+2]<c[i]) and (c[i+2]<c[i+1]) then
                begin
                        ctn:=c[i+2];
                        if c[i+1]<c[i] then
                        begin cth:=c[i+1];ccn:=c[i];end
                        else begin cth:=c[i];ccn:=c[i+1];
                        end;
                end;
        write(f,(ctn-d[3])*z+(cth-d[2]-ctn+d[3])*y+(ccn-d[1]-cth+d[2]+ctn-d[3])*x);
        close(f);
end;
begin
        nhap;
        xuly;
end.