import Qt3D.Core 2.12
import Qt3D.Render 2.0
import Qt3D.Extras 2.0


Entity {

    id: root

    property alias position: transform.translation
    property alias color: material.diffuse


    Transform {
        id: transform
        scale: 0.5
    }

    Mesh {
        id: mesh
        source: "models/box.obj"
    }

//    PhongMaterial {
//        id: material
//        diffuse: "green"
//    }

    DiffuseMapMaterial {
        id: material
        diffuse: TextureLoader { source: "qrc:/models/box.png" }
    }

    components: [material, mesh, transform]
}
