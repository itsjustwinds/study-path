var
        queuev1,queuev2,queuev3:array[1..1000000] of integer;
        dd:array[0..610,0..610,0..610] of boolean;
        tracev1,tracev2,tracev3:array[0..610,0..610,0..610] of integer;
        a:array[1..3] of integer;
        v1,v2,v3:integer;
procedure tinh(i,a,b,c:longint);
begin
        if (i=1) and (a>=b) then
        begin
                v1:=a-b;v2:=2*b;v3:=c;
        end;
        if (i=2) and (a>=c) then
        begin
                v1:=a-c;v2:=b;v3:=2*c;
        end;
        if (i=3) and (b>=a) then
        begin
                v1:=2*a;v2:=b-a;v3:=c;
        end;
        if (i=4) and (b>=c) then
        begin
                v1:=a;v2:=b-c;v3:=2*c;
        end;
        if (i=5) and (c>=a) then
        begin
                v1:=2*a;v2:=b;v3:=c-a;
        end;
        if (i=6) and (c>=b) then
        begin
                v1:=a;v2:=2*b;v3:=c-b;
        end;
end;
procedure result(v1,v2,v3:integer);
var     t1,t2,t3:integer;
        d,i:longint;
        cho,nhan:byte;
        kq1,kq2:array[1..100000] of byte;
begin
        d:=0;
        while (v1<>a[1]) or (v2<>a[2]) or (v3<>a[3]) do
        begin
                inc(d);
                t1:=tracev1[v1,v2,v3];
                t2:=tracev2[v1,v2,v3];
                t3:=tracev3[v1,v2,v3];
                if t1>v1 then cho:=1;
                if t1<v1 then nhan:=1;
                if t2>v2 then cho:=2;
                if t2<v2 then nhan:=2;
                if t3>v3 then cho:=3;
                if t3<v3 then nhan:=3;
                kq1[d]:=cho;
                kq2[d]:=nhan;
                v1:=t1;
                v2:=t2;
                v3:=t3;
        end;
        writeln(d);
        for i:=d downto 1 do
                writeln(kq1[i],' ',kq2[i]);
end;


procedure nhap;
begin
        readln(a[1],a[2],a[3]);
        fillchar(dd,sizeof(dd),true);
end;
procedure bfs;
var
        u,v:array[1..3] of integer;
        check:boolean;
        l,r,i:longint;
begin
        if ((a[1]=0)or(a[2]=0)or(a[3]=0)) then
        begin
                write(0);
                exit;
        end;
        u:=a;
        dd[u[1],u[2],u[3]]:=false;
        dd[u[1],u[3],u[2]]:=false;
        dd[u[2],u[1],u[3]]:=false;
        dd[u[2],u[3],u[1]]:=false;
        dd[u[3],u[1],u[2]]:=false;
        dd[u[3],u[2],u[1]]:=false;
        l:=1;r:=1;
        queuev1[1]:=a[1];
        queuev2[1]:=a[2];
        queuev3[1]:=a[3];
        check:=false;
        repeat
                u[1]:=queuev1[l];
                u[2]:=queuev2[l];
                u[3]:=queuev3[l];
                inc(l);
                for i:=1 to 6 do
                begin
                        v1:=0;v2:=0;v3:=0;
                        tinh(i,u[1],u[2],u[3]);
                        if (not((v1=0) and (v2=0) and (v3=0))) and (dd[v1,v2,v3]) then
                        begin
                                inc(r);
                                queuev1[r]:=v1;
                                queuev2[r]:=v2;
                                queuev3[r]:=v3;
                                tracev1[v1,v2,v3]:=u[1];
                                tracev2[v1,v2,v3]:=u[2];
                                tracev3[v1,v2,v3]:=u[3];
                                if ((v1=0) or (v2=0) or (v3=0)) then
                                begin
                                        result(v1,v2,v3);
                                        exit;
                                end;
                                dd[v1,v2,v3]:=false;
                                dd[v1,v3,v2]:=false;
                                dd[v2,v1,v3]:=false;
                                dd[v2,v3,v1]:=false;
                                dd[v3,v1,v2]:=false;
                                dd[v3,v2,v1]:=false;
                        end;
                end;
        until l>r;
end;
begin
        assign(input,'pour.inp');
        assign(output,'pour.out');
        reset(input);
        rewrite(output);
        nhap;
        bfs;
        close(input);
        close(output);
end.