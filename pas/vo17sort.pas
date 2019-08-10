uses math;
var
        a:array[1..15] of longint;
        s,kq,SKQ:string;
        i,j,res,n,l,r,t,lol1,lol2:longint;

        stmp,u,utmp,vtmp:string;
        q:array[1..1000000] of string;
        dtmp,k,d1,d2,kqmin:longint;
        dem:array[1..1000000] of byte;
        kq1,kq2:array[1..1000000] of string;
        dem1,dem2:array[1..1000000] of byte;
procedure sub1;
var     i,j:longint;
begin
        kq:='';
        for i:=1 to n do
                kq:=kq+chr(i+48);
        if s=kq then
        begin
                writeln(0);
                exit;
        end;
        l:=1;r:=1;
        q[1]:=s;
        dem[1]:=0;
        d1:=1;
        kq1[d1]:=s;
        dem1[d1]:=0;
        repeat
                u:=q[l];
                dtmp:=dem[l];
                inc(l);
                if dtmp<=1 then
                for i:=1 to n do
                        for j:=i to n do
                        begin
                                stmp:=copy(u,i,j-i+1);
                                utmp:=u;
                                delete(utmp,i,j-i+1);
                                for k:=i+1 to n-j+i do
                                begin
                                        vtmp:=utmp;
                                        insert(stmp,vtmp,k);
                                        inc(r);
                                        if vtmp=kq then
                                        begin
                                                writeln(dtmp+1);
                                                exit;
                                        end;
                                        q[r]:=vtmp;
                                        dem[r]:=dtmp+1;
                                        inc(d1);
                                        kq1[d1]:=vtmp;
                                        dem1[d1]:=dtmp+1;
                                end;
                        end;
        until l>r;

        l:=1;r:=1;
        q[1]:=kq;
        dem[1]:=0;
        d2:=1;
        kq2[d2]:=kq;
        dem2[d2]:=0;
        repeat
                u:=q[l];
                dtmp:=dem[l];
                inc(l);
                if dtmp<=1 then
                for i:=1 to n do
                        for j:=i to n do
                        begin
                                stmp:=copy(u,i,j-i+1);
                                utmp:=u;
                                delete(utmp,i,j-i+1);
                                for k:=i+1 to n-j+i do
                                begin
                                        vtmp:=utmp;
                                        insert(stmp,vtmp,k);
                                        inc(r);
                                        if vtmp=s then
                                        begin
                                                writeln(dtmp+1);
                                                exit;
                                        end;
                                        q[r]:=vtmp;
                                        dem[r]:=dtmp+1;
                                        inc(d2);
                                        kq2[d2]:=vtmp;
                                        dem2[d2]:=dtmp+1;
                                end;
                        end;
        until l>r;
        kqmin:=10;
        for i:=1 to d1 do
                for j:=1 to d2 do
                if kq1[i]=kq2[j] then
                if dem1[i]+dem2[j]<kqmin then
                        kqmin:=dem1[i]+dem2[j];
        if kqmin<>10 then writeln(kqmin)
        else
        writeln('5 or more');
end;
procedure nhap;
begin
        readln(t);
        while t>0 do
        begin
        dec(t);
        readln(n);
        for i:=1 to n do
                read(a[i]);
        s:='';
        for i:=1 to n do
                s:=s+chr(a[i]+48);
        sub1;
        end;
end;
begin
        {assign(input,'vo17sort.inp');
        assign(output,'vo17sort.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output); }
end.
