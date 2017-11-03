//
// Copyright(c) 2017 benikabocha.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//

#define TINYXLOADER_IMPLEMENTATION
#include "tinyxloader.h"

void Usage()
{
    std::cout << "example <xfile>\n";
}

int main(int argc, char** argv) {
    if (argc < 2) {
        Usage();
        return -1;
    }

    tinyxfile::XFileLoader loader;
    tinyxfile::XFile xfile;
    if (!loader.Load(argv[1], &xfile)) {
        std::cout << loader.GetErrorMessage() << "\n";
        return -1;
    }

    for (const auto& frame : xfile.m_frames) {
        std::cout << "Frame : " << frame->m_name << "\n";
        if (frame->m_parent) {
            std::cout << " Parent : " << frame->m_parent->m_name << "\n";
        }

        std::cout << " Child : " << frame->m_childFrames.size() << "\n";
        for (const auto& childFrame : frame->m_childFrames) {
            std::cout << "  " << childFrame->m_name << "\n";
        }

        std::cout << " Transform :\n";
        std::cout << "  [";
        for (int i = 0; i < 4 * 4; i++) {
            std::cout << frame->m_transform.m[i];
            if (i < (4 * 4 - 1)) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";

        std::cout << " Mesh : " << frame->m_mesh.m_name << "\n";
        std::cout << "  Positions : " << frame->m_mesh.m_positions.size() << "\n";
        for (const auto& pos : frame->m_mesh.m_positions) {
            std::cout << "   [" << pos.x << ", " << pos.y << ", " << pos.z << "]\n";
        }
        std::cout << "  PositionFaces : " << frame->m_mesh.m_positionFaces.size() << "\n";
        for (const auto& f : frame->m_mesh.m_positionFaces) {
            std::cout << "   [" << f.v1 << ", " << f.v2 << ", " << f.v3 << "]\n";
        }

        std::cout << "  Normals : " << frame->m_mesh.m_normals.size() << "\n";
        for (const auto& nor : frame->m_mesh.m_normals) {
            std::cout << "   [" << nor.x << ", " << nor.y << ", " << nor.z << "]\n";
        }
        std::cout << "  NormalFaces : " << frame->m_mesh.m_normalFaces.size() << "\n";
        for (const auto& f : frame->m_mesh.m_normalFaces) {
            std::cout << "   [" << f.v1 << ", " << f.v2 << ", " << f.v3 << "]\n";
        }

        std::cout << "  Texture Coords : " << frame->m_mesh.m_textureCoords.size() << "\n";
        for (const auto& coord : frame->m_mesh.m_textureCoords) {
            std::cout << "   [" << coord.x << ", " << coord.y << "]\n";
        }

        std::cout << "  Materials : " << frame->m_mesh.m_materials.size() << "\n";
        for (const auto& mat : frame->m_mesh.m_materials) {
            const auto& dif = mat.m_diffuse;
            const auto& spp = mat.m_specularPower;
            const auto& spc = mat.m_specular;
            const auto& emi = mat.m_emissive;
            std::cout << "   =======\n";
            std::cout << "   Diffuse : [" << dif.r << ", " << dif.g << ", " << dif.b << ", " << dif.a << "]\n";
            std::cout << "   Specular Power : [" << spp << "]\n";
            std::cout << "   Specular : [" << spc.r << ", " << spc.g << ", " << spc.b << "]\n";
            std::cout << "   Emissive : [" << emi.r << ", " << emi.g << ", " << emi.b << "]\n";
            std::cout << "   Texture : " << mat.m_texture << "\n";
        }

        std::cout << "  Face Materials : " << frame->m_mesh.m_materials.size() << "\n";
        for (auto mi : frame->m_mesh.m_faceMaterials) {
            std::cout << "   " << mi << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
